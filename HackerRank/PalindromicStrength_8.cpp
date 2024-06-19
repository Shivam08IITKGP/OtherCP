void solve()
{
    int n;
    string s;
    cin >> s;
    n = sz(s);
    graph dp(n, vi(n, 0));
    fr(i, n)
    {
        dp[i][i] = 1;
    }
    fr(i, n - 1)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = 1;
        }
    }
    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i <= n; i++)
        {
            int tar = i + len - 1;
            if (tar >= n)
            {
                break;
            }

            if (dp[i + 1][tar - 1])
            {
                if (s[i] == s[tar])
                {
                    dp[i][tar] = 1;
                }
            }
        }
    }
    vi startAt(n, 0);
    vi endAt(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (dp[i][j])
            {
                remax(startAt[i], j - i + 1);
                remax(endAt[j], j - i + 1);
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        remax(endAt[i], endAt[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        remax(startAt[i], startAt[i + 1]);
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        remax(ans, endAt[i] * startAt[i + 1]);
    }
    cout << ans << endl;
}
