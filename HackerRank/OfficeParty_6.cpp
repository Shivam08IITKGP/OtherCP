void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    graph g(n + 1);
    vi degree(n + 1, 0);
    vector<bool> attending(n + 1, true);
    fr(i, m)
    {
        int u, v;
        cin >> u >> v;
        g[v].pb(u);
        g[u].pb(v);
        degree[u]++;
        degree[v]++;
    }

    queue<int> q;
    rep(i, 1, n)
    {
        if (degree[i] < k)
        {
            q.push(i);
            attending[i] = false;
        }
    }

    while (!q.empty())
    {
        int not_attending = q.front();
        q.pop();

        for (auto &neigh : g[not_attending])
        {
            if (attending[neigh])
            {
                degree[neigh]--;
                if (degree[neigh] < k)
                {
                    q.push(neigh);
                    attending[neigh] = false;
                }
            }
        }
    }
    int ans = 0;
    rep(i, 1, n)
    {
        if (attending[i])
        {
            ans++;
        }
    }
    cout << ans << endl;
}
