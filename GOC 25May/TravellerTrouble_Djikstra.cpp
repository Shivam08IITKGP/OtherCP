#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define fir first
#define sec second
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;
#define int long long
#define INF 1e18

void solve()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    vector<pll> adj[n + 1];
    vector<pll> revadj[n + 1];
    vector<pair<pll, int>> edges(m);
    f(i, 0, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {{u, v}, w};
        adj[u].pb({v, w});
        revadj[v].pb({u, w});
    }
    vector<int> dist(n + 1, INF);
    vector<int> rdist(n + 1, INF);
    dist[x] = 0;
    rdist[y] = 0;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, x});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto p : adj[u])
        {
            int v = p.first;
            int w = p.second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = w + dist[u];
                pq.push({dist[v], v});
            }
        }
    }
    pq.push({0, y});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto p : revadj[u])
        {
            int v = p.first;
            int w = p.second;
            if (rdist[v] > rdist[u] + w)
            {
                rdist[v] = w + rdist[u];
                pq.push({rdist[v], v});
            }
        }
    }
    int dist_y = dist[y];
    for (auto edge : edges)
    {
        int dist_by_altering = min(dist[edge.fir.fir], dist[edge.fir.sec]) + min(rdist[edge.fir.fir], rdist[edge.fir.sec]);
        int dis = min(dist_y, dist_by_altering);
        if (dis >= INF)
        {
            cout << -1 << " ";
        }
        else
            cout << dis << " ";
    }
    cout << endl;
}

int32_t main()
{
    FAST;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
