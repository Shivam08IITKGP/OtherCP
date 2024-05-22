#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

ll MOD = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> adj[n + 1];
    f(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    function<void(ll, ll)> dfs = [&](ll node, ll parent)
    {
        dp[node][1] = 1;
        dp[node][0] = 1;

        for (auto child : adj[node])
        {
            if (child == parent)
            {
                continue;
            }
            dfs(child, node);
            dp[node][0] = (dp[node][0] * (dp[child][0] + dp[child][1])) % MOD;
            dp[node][1] = (dp[node][1] * dp[child][0]) % MOD;
        }
    };
    dfs(1, -1);
    cout << (dp[1][0] + dp[1][1]) % MOD << endl;
}

int main()
{
    FAST;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
