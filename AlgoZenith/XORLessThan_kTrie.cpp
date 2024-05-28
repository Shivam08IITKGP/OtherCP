#include <bits/stdc++.h>
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

struct TrieNode
{
    TrieNode *children[2];
    int count;

    TrieNode()
    {
        children[0] = nullptr;
        children[1] = nullptr;
        count = 0;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(ll n)
    {
        TrieNode *node = root;
        for (int i = 31; i >= 0; --i)
        {
            int bit = (n >> i) & 1LL;
            if (!node->children[bit])
            {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
            node->count++;
        }
    }

    int countLessThanK(ll prefixXOR, ll k)
    {
        TrieNode *node = root;
        int count = 0;

        for (int i = 31; i >= 0; --i)
        {
            int p_bit = (prefixXOR >> i) & 1LL;
            int k_bit = (k >> i) & 1LL;

            if (k_bit == 1)
            {
                if (node->children[p_bit])
                {
                    count += node->children[p_bit]->count;
                }
                if (node->children[1 - p_bit])
                {
                    node = node->children[1 - p_bit];
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (node->children[p_bit])
                {
                    node = node->children[p_bit];
                }
                else
                {
                    break;
                }
            }
        }

        return count;
    }

    ~Trie()
    {
        delete root;
    }
};

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Trie trie;
        trie.insert(0); // Initial prefix XOR of 0

        ll prefixXOR = 0;
        ll result = 0;

        for (int i = 0; i < n; i++)
        {
            prefixXOR ^= arr[i];
            result += trie.countLessThanK(prefixXOR, k);
            trie.insert(prefixXOR);
        }

        cout << result << endl;
    }
}

int main()
{
    FAST;
    solve();
    return 0;
}
