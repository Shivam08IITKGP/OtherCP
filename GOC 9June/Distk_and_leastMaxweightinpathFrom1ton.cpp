void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vii> g(n + 1);
    int wMax = 0;
    fr(i, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
        remax(wMax, w);
    }

    auto check = [&](int w_max) -> bool
    {
        vi vis(n + 1, 0);
        queue<ii> q;
        vis[1] = 1;
        q.push({1, 0});
        while (!q.empty())
        {
            auto [x, dist] = q.front();
            q.pop();
            if (x == n)
            {
                return true;
            }
            if (dist == k)
            {
                continue;
            }
            for (auto edge : g[x])
            {
                if (edge.S <= w_max and !vis[edge.F])
                {
                    vis[edge.F] = 1;
                    q.push({edge.F, dist + 1});
                }
            }
        }
        return false;
    };

    if (!check(wMax))
    {
        cout << -1 << endl;
        return;
    }

    int l = 0, r = wMax;
    while (l < r)
    {
        int w = (l + r) / 2;
        if (check(w))
        {
            r = w;
        }
        else
        {
            l = w + 1;
        }
    }
    cout << l << endl;
}
