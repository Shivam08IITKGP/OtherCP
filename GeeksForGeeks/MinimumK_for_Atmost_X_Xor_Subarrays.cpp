// Contest - 183
class Solution {
  public:
  class TrieNode {
    public:
        TrieNode* children[2];
        int cnt;

        TrieNode() {
            children[0] = nullptr;
            children[1] = nullptr;
            cnt = 0;
        }
    };

    void insert(TrieNode* root, int prefXor) {
        TrieNode* node = root;
        for (int i = 20; i >= 0; --i) {
            int bit = (prefXor >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
            node->cnt++;
        }
    }

    int countSubarrayHelper(TrieNode* root, int prefXor, int k) 
    {
        int res = 0;
        TrieNode* node = root;
        for (int i = 20; i >= 0; --i) 
        {
            int prefBit = (prefXor >> i) & 1;
            int kBit = (k >> i) & 1;

            // Case 1
            if (kBit == 0 && prefBit == 0) 
            {
                if (node->children[0]) 
                {
                    node = node->children[0];
                } 
                else 
                {
                    break;
                }
            }
            // Case 2
            else if (kBit == 0 && prefBit == 1) {
                if (node->children[1]) {
                    node = node->children[1];
                } else {
                    break;
                }
            }
            // Case 3
            else if (kBit == 1 && prefBit == 0) {
                if (node->children[0]) {
                    res += node->children[0]->cnt;
                }
                if (node->children[1]) {
                    node = node->children[1];
                } else {
                    break;
                }
            }
            // Case 4
            else if (kBit == 1 && prefBit == 1) {
                if (node->children[1]) {
                    res += node->children[1]->cnt;
                }
                if (node->children[0]) {
                    node = node->children[0];
                } else {
                    break;
                }
            }
          // We are not adding the results when kBit = 0, because 0^1 = 1, which increases the value of xor by 1
          // As we do not want to risk of getting higher number, we only add the results given by the kBit = 1
          
        }
        return res;
    }

    int countSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        int prefXor = 0;
        int cnt = 0;
        TrieNode* root = new TrieNode();
        for (int i = 0; i < n; ++i) {
            insert(root, prefXor);
            prefXor ^= arr[i];
            cnt += countSubarrayHelper(root, prefXor, k);
        }
        return cnt;
    }
    int minimizeKForXOR(int x, vector<int>& arr) {
        int lo = 0, hi = 2 * *max_element(arr.begin(), arr.end());
        int res = 0;
        while (lo <= hi) 
        {
            int mid = (lo + hi) / 2;
            if (countSubarrays(arr, mid + 1) >= x) 
            {
                res = mid;
                hi = mid - 1;
            } 
            else 
            {
                lo = mid + 1;
            }
        }
        return res;
    }
};
