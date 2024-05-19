#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

int pr[1000001];

void pre()
{
    for (int i = 2; i <= 1e6; i++)
    {
        if (!pr[i])
            // If i is prime
            for (int j = i; j <= 1e6; j += i)
                pr[j]++;
    }
}

void solve()
{
    int n, x;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    // Min-Heap
    // Because we want the minimum the first element of the queue
    // That is getting updated every time we are encountering the same node
    // So if we get the same node with a smaller weight, then we continue in the loop
    // After that we check for its neighbouring nodes(djiikstra's algorithm)
    pq.push({0, {0, 0}});
    dist[0][0] = 0;

    while (!pq.empty())
    {
        int x = pq.top().second.first, y = pq.top().second.second, w = pq.top().first;
        pq.pop();
        if (dist[x][y] < w)
            continue;
        int p = pr[a[x][y]];
        for (int i = -p; i <= p; i++)
        {
            for (int j = -p; j <= p; j++)
            {
                int nx = x + i, nj = y + j;
                if (nx >= 0 && nx < n && nj >= 0 && nj < n && (abs(i) + abs(j) <= p))
                {
                    if (dist[nx][nj] > w + (int)sqrt(a[x][y]))
                    {
                        dist[nx][nj] = w + (int)sqrt(a[x][y]);
                        pq.push({dist[nx][nj], {nx, nj}});
                    }
                }
            }
        }
    }
    cout << dist[n - 1][n - 1]<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pre();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
}
