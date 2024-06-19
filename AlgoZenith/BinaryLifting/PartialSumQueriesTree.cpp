graph tree;
vi depth;
graph par;
graph dp;
vi val;

void dfs(int node, int p, int dep)
{
    par[node][0] = p;
    depth[node] = dep;
    for (int i = 1; i < 30; i++)
    {
        par[node][i] = par[par[node][i - 1]][i - 1];
    }
    for (auto &chi : tree[node])
    {
        if (chi == p)
            continue;
        dfs(chi, node, dep + 1);
    }
}

void dfs2(int node, int p)
{
    for (auto &chi : tree[node])
    {
        if (chi == p)
            continue;
        dfs2(chi, node);
    }
    val[par[node][0]] += val[node];
}
int lca(int u, int v)
{
    if (depth[u] < depth[v])
    {
        swap(u, v);
    }

    per(i, 29, 0)
    {
        if ((depth[u] - depth[v]) & (1LL << i))
        {
            u = par[u][i];
        }
    }
    if (u == v)
        return u;

    per(i, 29, 0)
    {
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

void solve()
{
    int n;
    cin >> n;
    tree.resize(n + 1);
    depth.resize(n + 1);
    val.resize(n + 1);
    par.assign(n + 1, vi(30, 0));
    dp.assign(n + 1, vi(30, 0));
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0, 1);
    int q;
    cin >> q;
    while (q--)
    {
        int u, v, z;
        cin >> u >> v >> z;
        int l = lca(u, v);
        val[u] += z;
        val[v] += z;
        int lca_ = lca(u, v);
        val[lca_] -= z;
        val[par[lca_][0]] -= z;
    }
    dfs2(1, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << val[i] << " ";
    }
}
