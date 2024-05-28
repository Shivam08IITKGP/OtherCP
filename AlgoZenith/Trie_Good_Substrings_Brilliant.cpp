#include <bits/stdc++.h>
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& s, int start, int end) {
        TrieNode* node = root;
        for (int i = start; i <= end; ++i) {
            int index = s[i] - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    int countDistinctSubstrings() {
        return countDistinctSubstringsHelper(root);
    }

private:
    TrieNode* root;

    int countDistinctSubstringsHelper(TrieNode* node) {
        if (!node) return 0;
        int count = 0;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (node->children[i]) {
                count += countDistinctSubstringsHelper(node->children[i]);
            }
        }
        return count + node->isEndOfWord;
    }
};

void solve() {
    string s;
    cin >> s;
    string badChars;
    cin >> badChars;
    int k;
    cin >> k;
    
    int n = s.size();
    vector<int> isBad(26, 0);
    for (int i = 0; i < 26; ++i) {
        isBad[i] = (badChars[i] == '0') ? 1 : 0;
    }
    
    Trie trie;
    
    for (int i = 0; i < n; ++i) {
        int bad_count = 0;
        for (int j = i; j < n; ++j) {
            if (isBad[s[j] - 'a'] == 1) {
                ++bad_count;
            }
            if (bad_count > k) {
                break;
            }
            trie.insert(s, i, j);
        }
    }
    
    cout << trie.countDistinctSubstrings() << endl;
}

int main() {
    FAST;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
