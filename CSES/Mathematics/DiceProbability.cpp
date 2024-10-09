void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    double dp[601][101] = {0};
    // n is upto 100 only , and a, b are upto 600
    dp[0][0] = 1.0;
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i < 601; i++)
        {
            for (int k = 1; k <= 6; k++)
            {
                if (i - k >= 0)
                    dp[i][j] += dp[i - k][j - 1] * (1.0 / 6);
            }
        }
    }
    double ans = 0.0;
    for(int i = a;i<=b;i++)
    {
        ans += dp[i][n];
    }
    // Every ith row contains the probability of achieving the jth number in the ith throw
    cout << fixed << setprecision(6) << ans << endl;
}
