void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>());
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
            if (node == n - 1)
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
            if (mask & (1LL << (c)))
                continue;
            ans += dfs(c, mask | 1LL << (c));
        }
        return ans;
    };
    int ans = dfs(0, 1);
    cout << ans << endl;
}
