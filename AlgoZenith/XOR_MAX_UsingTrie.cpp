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

    void deletion(ll n)
    {
        TrieNode *node = root;
        for (int i = 31; i >= 0; --i)
        {
            int bit = (n >> i) & 1LL;
            if (!node->children[bit])
            {
                return;
            }
            node = node->children[bit];
            node->count--;
        }
    }

    ll findMaxXor(ll n)
    {
        TrieNode *node = root;
        ll ans = 0;
        for (int i = 31; i >= 0; --i)
        {
            int bit = (n >> i) & 1LL;
            if (node->children[!bit] && node->children[1 ^ bit]->count > 0)
            {
                ans += (1LL << i);
                node = node->children[1 ^ bit];
            }
            else
            {
                node = node->children[bit];
            }
        }
        return ans;
    }
};

void solve()
{
    int q;
    cin >> q;
    Trie trie;
    trie.insert(0);
    while (q--)
    {
        char c;
        cin >> c;
        if (c == '+')
        {
            ll x;
            cin >> x;
            trie.insert(x);
        }
        else if (c == '-')
        {
            ll x;
            cin >> x;
            trie.deletion(x);
        }
        else
        {
            ll x;
            cin >> x;
            cout << trie.findMaxXor(x) << endl;
        }
    }
}

int main()
{
    FAST;
    int t = 1;
    while (t--)
    {
        solve();
    }
}
