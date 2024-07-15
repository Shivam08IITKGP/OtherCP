class Solution 
{
public:
    string longestCommonPrefix(int n, string arr[]) 
    {
        if (n == 0) return "-1";

        // Initialize the trie
        vector<vector<int>> trie(1, vector<int>(26, -1));
        vector<int> isend(1, 0);
        int nodeCount = 1;

        // Build the trie
        int min_length = INT_MAX;
        for (int i = 0; i < n; ++i) 
        {
            string& str = arr[i];
            min_length = min(min_length, (int)str.length());
            int cnt = 0;
            for (char c : str) 
            {
                if (trie[cnt][c - 'a'] == -1) 
                {
                    trie[cnt][c - 'a'] = nodeCount;
                    trie.push_back(vector<int>(26, -1));
                    isend.push_back(0);
                    nodeCount++;
                }
                cnt = trie[cnt][c - 'a'];
            }
            isend[cnt] = 1; 
        }

        // Find the longest common prefix
        int cnt = 0;
        string result = "";
        for (int i = 0; i < min_length; ++i) 
        {
            int nextCharIndex = -1;
            for (int j = 0; j < 26; ++j) 
            {
                if (trie[cnt][j] != -1) 
                {
                    if (nextCharIndex != -1) 
                    {
                        return result.empty() ? "-1" : result; // More than one child node, so break
                    }
                    nextCharIndex = j;
                }
            }
            if (nextCharIndex == -1) 
            {
                break;
            }
            result += (char)('a' + nextCharIndex);
            cnt = trie[cnt][nextCharIndex];
        }

        return result.empty() ? "-1" : result;
    }
};
