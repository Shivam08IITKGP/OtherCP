const int INF = 1LL << 60;// 1e18 is not working due to edge test cases
graph multiply(const graph &a, const graph &b)
{
    int n = a.size();
    graph res(n, vi(n, INF));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (a[i][k] < INF && b[k][j] < INF)
                {
                    res[i][j] = min(res[i][j], a[i][k] + b[k][j]);
                  // Important step
                  /*
                  If you need to find number of paths then multiply, else if you need to find length, then add
                  */
                }
            }
        }
    }
    return res;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    graph g(n + 1, vi(n + 1, INF));// Important

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        remin(g[a][b], c);
      // Important
    }

    graph y(n + 1, vi(n + 1, INF));
    for (int i = 1; i <= n; i++)
    {
        y[i][i] = 0;
    }
    // Important -> matrix y

    while (k)
    {
        if (k & 1)
        {
            y = multiply(y, g);
        }
        g = multiply(g, g);
        k >>= 1;
    }

    if (y[1][n] >= INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << y[1][n] << endl;
    }
}
