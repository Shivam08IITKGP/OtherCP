void solve()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<string> g(n);
    for (auto &s : g)
    {
        cin >> s;
    }
    vector<vector<int>> dp(n, vector<int>(m, n + m + 10));
    if (g[0][0] == '.')
    {
        dp[0][0] = 0;
    }
    else
    {
        dp[0][0] = 1;
    }
    fr(i, n)
    {
        fr(j, m)
        {
            if (i - 1 >= 0 and g[i][j] == '#' and g[i - 1][j] == '.')
            {
                remin(dp[i][j], dp[i - 1][j] + 1);
            }
            else if (i - 1 >= 0)
            {
                remin(dp[i][j], dp[i - 1][j]);
            }
            if (j - 1 >= 0 and g[i][j] == '#' and g[i][j - 1] == '.')
            {
                remin(dp[i][j], dp[i][j - 1] + 1);
            }
            else if (j - 1 >= 0)
            {
                remin(dp[i][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n - 1][m - 1] << endl;
}
