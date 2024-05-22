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

vector<int> adj[200005];
vector<vector<int>> dp(200005, vector<int>(2, 0));

void solve()
{
    int n;
    cin >> n;
    f(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

  // dp[i][1] means we are taking i and one its child as one edge
  // dp[i][0] means we are not taking i and one of its child as an edge

    f(i, 0, n + 1)
    {
        dp[i][0] = dp[i][1] = 0;
    }
    function<void(int, int)> dfs_DP = [&](int u, int p)
    {
        for (auto v : adj[u])
        {
            if (v == p)
            {
                continue;
            }
            dfs_DP(v, u);
            dp[u][0] = max(dp[u][0], max(dp[v][0], dp[v][1]));
        }

        for (auto v : adj[u])
        {
            if (v == p)
            {
                continue;
            }
            // dfs_DP(v,u);
            dp[u][1] = max(dp[u][1], 1 + dp[v][0] + dp[u][0] - max(dp[v][0], dp[v][1]));
          // -max(dp[v][0],dp[v][1]) is because we are breaking the structure of the child v
          // and making a new edge u-v 
          // 1+ no taking u + no taking v is the new structure
        }
    };

    bool done[200005] = {0};
    int ans = 0;
    function<void(int, int)> dfs_greedy = [&](int u, int p)
    {
        for (auto v : adj[u])
        {
            if (v == p)
            {
                continue;
            }
            dfs_greedy(v, u);
            if (!done[u] and !done[v])
            {
                done[u] = 1;
                done[v] = 1;
                ans++;
            }
        }
    };
    dfs_DP(1, -1);
    dfs_greedy(1, -1);
    cout << max(dp[1][0], dp[1][1]) << endl;
    cout<<ans<<endl;
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
