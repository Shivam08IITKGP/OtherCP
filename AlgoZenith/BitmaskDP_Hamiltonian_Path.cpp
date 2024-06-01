void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1, vector<int>());
    rep(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
    }
    function<int(int, int)> dfs = [&](int node, int mask) -> int
    {
        if (mask == (1LL << n) - 1)
        {
            if (node == n)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        int ans = 0;
        for (auto c : g[node])
        {
            if (mask & (1LL << (c-1)))
                continue;
            ans += dfs(c, mask | 1LL << (c-1));
        }
        return ans;
    };
    int ans = dfs(1, 1);
    cout << ans << endl;
}
