#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define v vector
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

vector<pair<int, int>> adj[1001];
int n, m;

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        char c;
        cin >> u >> v >> c;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
    }
    queue<pii> frontier;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));
    bool possible = false;
    for (int i = 1; i <= n; i++)
    {
        frontier.push({i, i});
        dist[i][i]=0;
        for (const auto &[x, _] : adj[i])
        {
            if (dist[i][x] == INT_MAX)
            {
                dist[i][x] = dist[x][i] = 1;
                frontier.push({i, x});
            }
        }
    }

    while (!frontier.empty())
    {
        auto [u, v] = frontier.front();
        frontier.pop();

        if ((u == 1 and v == n) or (v == 1 and u == n))
        {
            possible = true;
            break;
        }

        int newdist = dist[u][v] + 2;
        for (const auto &[x, c] : adj[u])
        {
            for (const auto &[y, d] : adj[v])
            {
                if (c == d and dist[x][y] > newdist)
                {
                    dist[x][y] = dist[y][x] = newdist;
                    frontier.push({x, y});
                }
            }
        }
    }
    cout << (possible ? dist[1][n] : -1) << endl;
}

int main()
{
    FAST;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
