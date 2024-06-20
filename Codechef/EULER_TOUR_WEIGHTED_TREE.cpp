// https://www.codechef.com/IRLY1601/problems/REL203
void solve()
{
    int n;
    cin >> n;
    wgraph g(n + 1);
    rep(i, 1, n - 1)
    {
        int u, v, w;
        read(u, v, w);
        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    int ans = 0;
    int max_w_depth = 0;

    function<void(int, int)> dfs = [&](int node, int p) -> void
    {
        for (auto c : g[node])
        {
            if (c.F != p)
            {
                ans += c.S;
                dfs(c.F, node);
                ans += c.S;
            }
        }
    };

    function<void(int, int, int)> dfs2 = [&](int node, int p, int w) -> void
    {
        for (auto c : g[node])
        {
            if (c.F != p)
            {
                remax(max_w_depth, c.S + w);
                dfs2(c.F, node, w + c.S);
            }
        }
    };

    dfs(1, 0);
    dfs2(1, 0, 0);
    cout << ans - max_w_depth << endl;
}
