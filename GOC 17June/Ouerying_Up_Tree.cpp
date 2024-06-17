#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e5 + 5;
const int LOG = 22;
const int INF = 1e18;

vector<pair<int, int>> adj[MAXN];
int up[MAXN][LOG];
int depth[MAXN];
int edgeAnd[MAXN][LOG];
int edgeOr[MAXN][LOG];
int edgeXor[MAXN][LOG];
int dist[MAXN];

void dfs(int node, int parent, int weight, int d, int xor_val)
{
    up[node][0] = parent;
    edgeAnd[node][0] = weight;
    edgeOr[node][0] = weight;
    edgeXor[node][0] = weight;
    dist[node] = d;
    for (int i = 1; i < LOG; ++i)
    {
        if (up[node][i - 1] != -1)
        {
            up[node][i] = up[up[node][i - 1]][i - 1];
            edgeAnd[node][i] = edgeAnd[node][i - 1] & edgeAnd[up[node][i - 1]][i - 1];
            edgeOr[node][i] = edgeOr[node][i - 1] | edgeOr[up[node][i - 1]][i - 1];
            edgeXor[node][i] = edgeXor[node][i - 1] ^ edgeXor[up[node][i - 1]][i - 1];
        }
        else
        {
            up[node][i] = -1;
            edgeAnd[node][i] = INF;
            edgeOr[node][i] = 0;
            edgeXor[node][i] = 0;
        }
    }
    for (auto &[next, w] : adj[node])
    {
        if (next != parent)
        {
            depth[next] = depth[node] + 1;
            dfs(next, node, w, d + w, xor_val ^ w);
        }
    }
}

int get_lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    for (int i = LOG - 1; i >= 0; --i)
    {
        if (up[u][i] != -1 && depth[u] - (1 << i) >= depth[v])
        {
            u = up[u][i];
        }
    }
    if (u == v)
        return u;
    for (int i = LOG - 1; i >= 0; --i)
    {
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int get_and_path(int u, int v)
{
    int lca = get_lca(u, v);
    int res = (1LL << (LOG)) - 1;

    auto path_and = [&](int x)
    {
        int cur_and = (1LL << (LOG)) - 1;
        for (int i = LOG - 1; i >= 0; --i)
        {
            if (up[x][i] != -1 && depth[x] - (1 << i) >= depth[lca])
            {
                cur_and &= edgeAnd[x][i];
                x = up[x][i];
            }
        }
        return cur_and;
    };

    res &= path_and(u);
    res &= path_and(v);
    return res;
}

int get_or_path(int u, int v)
{
    int lca = get_lca(u, v);
    int res = 0;

    auto path_or = [&](int x)
    {
        int cur_or = 0;
        for (int i = LOG - 1; i >= 0; --i)
        {
            if (up[x][i] != -1 && depth[x] - (1 << i) >= depth[lca])
            {
                cur_or |= edgeOr[x][i];
                x = up[x][i];
            }
        }
        return cur_or;
    };

    res |= path_or(u);
    res |= path_or(v);
    return res;
}

int get_xor_path(int u, int v)
{
    int lca = get_lca(u, v);
    int res = 0;

    auto path_xor = [&](int x)
    {
        int cur_xor = 0;
        for (int i = LOG - 1; i >= 0; --i)
        {
            if (up[x][i] != -1 && depth[x] - (1 << i) >= depth[lca])
            {
                cur_xor ^= edgeXor[x][i];
                x = up[x][i];
            }
        }
        return cur_xor;
    };

    res ^= path_xor(u);
    res ^= path_xor(v);
    return res;
}

void reset(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        adj[i].clear();
        fill(up[i], up[i] + LOG, -1);
        fill(edgeAnd[i], edgeAnd[i] + LOG, 1LL << (LOG)-1);
        fill(edgeOr[i], edgeOr[i] + LOG, 0);
        fill(edgeXor[i], edgeXor[i] + LOG, 0);
        depth[i] = 0;
        dist[i] = 0;
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    reset(n);

    for (int i = 1; i < n; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    dfs(1, -1, INF, 0, 0);

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        int and_path_value = get_and_path(u, v);
        int or_path_value = get_or_path(u, v);
        int xor_path_value = get_xor_path(u, v);
        // cout << and_path_value << " " << or_path_value << " " << xor_path_value << endl;
        cout << (and_path_value + or_path_value + xor_path_value) << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
