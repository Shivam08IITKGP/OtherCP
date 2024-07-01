struct TrieNode {
    TrieNode *children[26];
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

class Trie {

public:
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode *node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return node->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return true;
    }

    ~Trie() {
        delete root;
    }
};

int Solution::wordBreak(string A, vector<string> &B) 
{
    Trie trie;
    int n = A.size();
    for (auto &b : B) 
    {
        trie.insert(b);
    }

    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        TrieNode* node = trie.root;
        for (int j = i; j >= 1; j--) {
            int letter = A[j - 1] - 'a';
            if (node->children[letter] == NULL) {
                break;
            }
            node = node->children[letter];
            if (node->isEndOfWord and dp[j-1]) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];    
}
