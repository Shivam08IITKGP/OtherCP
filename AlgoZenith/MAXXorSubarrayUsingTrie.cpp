#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;

struct TrieNode {
    TrieNode *children[2];
    int count;

    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
        count = 0;
    }
};

class Trie {
private:
    TrieNode *root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(ll n) {
        TrieNode *node = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (n >> i) & 1LL;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
            node->count++;
        }
    }

    void deletion(ll n) {
        TrieNode *node = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (n >> i) & 1LL;
            if (!node->children[bit]) {
                return;
            }
            node = node->children[bit];
            node->count--;
        }
    }

    ll findMaxXor(ll n) {
        TrieNode *node = root;
        ll ans = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (n >> i) & 1LL;
            if (node->children[!bit] && node->children[1 ^ bit]->count > 0) {
                ans += (1LL << i);
                node = node->children[1 ^ bit];
            }
            else {
                node = node->children[bit];
            }
        }
        return ans;
    }

    ~Trie() {
        delete root;
    }
};

void solve()
{
    int n;
    cin>>n;
    vll a(n);
    f(i,0,n) cin>>a[i];

    Trie trie;
    vll prefixXOR(n+1);
    f(i,1,n+1) prefixXOR[i] = prefixXOR[i-1] ^ a[i-1];
    f(i,0,n+1) trie.insert(prefixXOR[i]);
    ll ans= *max_element(begin(a),end(a));

    f(i,1,n+1)
    {
        ans=max(ans,trie.findMaxXor(prefixXOR[i]));        
    }
    cout<<ans<<endl;
}

int main()
{
    FAST;
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
