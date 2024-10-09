void multiply(graph &a, graph &b)
{
    int n = a.size();
    graph res(n, vi(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                res[i][j] += (a[i][k] * b[k][j]) % N;
                res[i][j] %= N;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = res[i][j];
        }
    }
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    graph g(n + 1, vi(n + 1, 0));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a][b]++;
    }

    graph y(n + 1, vi(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        y[i][i] = 1;
    }

    while (k)
    {
        if (k & 1)
        {
            multiply(y, g);
        }
        multiply(g, g);
        k >>= 1;
    }
    cout << y[1][n] << endl;
}
// Backchod sawaal, ismein g[a][b] ++ krna hai naaki g[a][b] = 1
