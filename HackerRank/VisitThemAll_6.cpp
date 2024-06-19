const int INF = 1e18;

vector<vector<int>> adj;
vector<vector<int>> dp;

int mem(int bitmask, int town)
{
    if (dp[bitmask][town] != -1)
    {
        return dp[bitmask][town];
    }
    if (bitmask == 0)
    {
        return dp[0][town] = adj[0][town];
    }

    dp[bitmask][town] = INF;
    for (int i = 0; i < 20; i++)
    {
        if ((bitmask >> i) & 1)
        {
            remin(dp[bitmask][town], mem(bitmask ^ (1 << i), i) + adj[i][town]);
        }
    }
    return dp[bitmask][town];
}

void solve()
{
    int n, m;
    read(n, m);
    adj.assign(n, vector<int>(n, INF));
    dp.assign(1 << (n + 1), vector<int>(n + 1, -1));

    rep(i, 0, n - 1)
    {
        adj[i][i] = 0;
    }

    rep(i, 1, m)
    {
        int u, v, w;
        read(u, v, w);
        adj[u - 1][v - 1] = w;
        adj[v - 1][u - 1] = w;
    }

    // Floyd-Warshall Algorithm to find all pairs shortest paths
    rep(k, 0, n - 1)
    {
        rep(i, 0, n - 1)
        {
            rep(j, 0, n - 1)
            {
                if (adj[i][k] < INF && adj[k][j] < INF)
                {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    /*

    1) When the bitmask is zero, we have only started from node 0 to node town
    2) So we add the cost of town 0 to that town
    3) When bitmask is filled with 1, it means that every city is transfered to node n
    4) 



    */

    int ans = INF;
    for (int i = 0; i < n; i++)
    {
        remin(ans, mem(((1 << n) - 1) ^ (1 << i), i) + adj[i][n - 1]);
    }
    cout << ans << endl;
}
