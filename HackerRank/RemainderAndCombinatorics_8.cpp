void solve()
{
    string a;
    cin >> a;
    int n = sz(a);
    graph dp(n + 1, vi(13, 0));
    dp[n][0] = 1;

    for (int i = n - 1, pw = 1; i >= 0; i--, pw = (pw * 10) % 13)
    {
        for (int j = 0; j < 10; j++)
        {
            if (a[i] == '0' + j or a[i] == '?')
            {
                for (int k = 0; k < 13; k++)
                {
                    int new_rem = (j * pw + k) % 13;
                    dp[i][new_rem] = (dp[i][new_rem] + dp[i + 1][k]) % N;
                }
            }
        }
    }
    cout << dp[0][5] << endl;
}
