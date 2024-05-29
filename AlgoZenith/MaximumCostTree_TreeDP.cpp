#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define per(i, start, end) for (ll i = start; i >= end; i--)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define F first
#define S second
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;
#define int long long

vector<int> indp(200005);
vector<int> outdp(200005);
vector<int> sum(200005);
void solve()
{
    int n;
    cin >> n;

    sum.clear();
    indp.clear();
    outdp.clear();
    vector<int> a(n + 1);
    rep(i, 1, n)
    {
        cin >> a[i];
    }
    int totalsum = accumulate(all(a), 0);

    vector<int> adj[n + 1];
    fr(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    function<void(int, int)> dfs1 = [&](int u, int par)
    {
        for (auto v : adj[u])
        {
            if (v != par)
            {
                dfs1(v, u);
                indp[u] += indp[v] + sum[v] + a[v];
                sum[u] += sum[v] + a[v];
            }
        }
    };

    function<void(int, int)> dfs2 = [&](int node, int par)
    {
        for (auto child : adj[node])
        {
            if (child != par)
            {
                outdp[child] += outdp[node] + (totalsum - sum[node]) + (indp[node] - indp[child] - sum[child] - a[child]) + (sum[node] - sum[child] - a[child]);
                dfs2(child, node);
            }
        }
    };

    dfs1(1, -1);
    dfs2(1, -1);
    int ans = INT_MAX;

    rep(i, 1, n)
    {
        ans = min(ans, outdp[i] + indp[i]);
    }

    cout << ans << " ";

    rep(i, 1, n)
    {
        ans = max(ans, outdp[i] + indp[i]);
    }

    cout << ans << endl;
}

int32_t main()
{
    FAST;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
