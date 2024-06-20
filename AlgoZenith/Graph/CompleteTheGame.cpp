/*
There are no cycles in the graph, n nodes, m edges. Find the number of ways to go from node 1 to n
Topological Sort
*/
void solve()
{
    int n, m;
    cin >> n >> m;
    graph g(n + 1);
    vi indeg(n + 1);
    fr(i, m)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        indeg[v]++;
    }

    queue<int> q;
    vi top;
    rep(i, 1, n)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    vi dp(n + 1, 0);
    dp[1] = 1;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        // top.pb(f);
        for (auto chi : g[f])
        {
            if (--indeg[chi] == 0)
            {
                q.push(chi);
            }
        }
        for (auto chi : g[f])
        {
            dp[chi] = (dp[chi] + dp[f]) % N;
        }
    }

        cout << dp[n] << endl;
}
