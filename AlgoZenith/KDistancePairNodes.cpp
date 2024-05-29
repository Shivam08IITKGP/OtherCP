#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define per(i, start, end) for (ll i = start; i >= end; i--)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define F first
#define S second
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> adj[n + 1];
    fr(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int ans = 0;
    vector<vi> dp(n + 1, vi(k + 1, 0));
    function<void(int, int)> dfs = [&](int node, int parent)
    {
        dp[node][0] = 1;
        for (auto child : adj[node])
        {
            if (child != parent)
            {
                dfs(child, node);
                for (int j = 1; j <= k; j++)
                {
                    ans += dp[child][j - 1] * dp[node][k - j];
                }
                for (int j = 1; j <= k; j++)
                {
                    dp[node][j] += dp[child][j - 1];
                }
            }
        }
    };
    dfs(1,-1);
    cout<<ans<<endl;
}

int32_t main()
{
    FAST;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
