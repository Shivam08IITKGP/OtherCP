graph g;
int dp[V][30], par[V][30];
vi val;
vi depth;

void dfs(int node, int prev, int dep)
{
    par[node][0] = prev;
    dp[node][0] = val[node];
    depth[node] = dep;
    for (int i = 1; i <= 29; i++)
    {
        par[node][i] = par[par[node][i - 1]][i - 1];
        dp[node][i] = __gcd(dp[node][i - 1], dp[par[node][i - 1]][i - 1]);
    }

    for (auto ch : g[node])
    {
        if (ch != prev)
        {
            dfs(ch, node, dep + 1);
        }
    }
}

int query(int u, int v)
{
    if (depth[u] < depth[v])
    {
        swap(u, v);
    }
    int gcd = 0;

    for (int i = 29; i >= 0; i--)
    {
        if ((depth[u] - depth[v]) & (1LL << i))
        {
            gcd = __gcd(gcd, dp[u][i]);
            u = par[u][i];
        }
    }

    // Now u and v are at the same level
    if (u == v)
        return __gcd(gcd, val[u]);

    for (int i = 29; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            gcd = __gcd(gcd, dp[u][i]);
            gcd = __gcd(gcd, dp[v][i]);
            u = par[u][i];
            v = par[v][i];
        }
    }
    gcd = __gcd(gcd, dp[u][0]);
    gcd = __gcd(gcd, dp[v][0]);
    gcd = __gcd(gcd, val[par[u][0]]);
    return gcd;
}

void solve()
{
    int n, q;
    read(n, q);
    g.clear();
    g.resize(n + 1);
    val.clear();
    val.resize(n + 1);
    depth.clear();
    depth.resize(n + 1);
    fr(i, n)
    {
        cin >> val[i + 1];
    }
    memset(dp, 0, sizeof(dp));
    memset(par, 0, sizeof(par));
    fr(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, -1, 0);

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << query(u, v) << endl;
    }
}
