void solve()
{
    int K;
    cin >> K;
    int n = 8, sz = 64;
    vector<vector<double>> dp(K + 1, vector<double>(sz, 0.0));
    vector<double> ans(64, 1.0);

    for (int i = 0; i < sz; i++)
    {
        dp.assign(K + 1, vector<double>(sz, 0.0));
        dp[0][i] = 1.0;
        // Notice that only dp[0][i] is 1.0,
        // That means we are calculating the probability of empty square
        // By considering effect of every robots one by one
        // That is what outer loop is for
        for (int k = 0; k < K; k++)
        {
            for (int u = 0; u < sz; u++)
            {
                vector<int> v;
                if (u >= n)
                    v.pb(u - n);
                if (u < sz - n)
                    v.pb(u + n);
                if (u % n != n - 1)
                    v.pb(u + 1);
                if (u % n != 0)
                    v.pb(u - 1);
                for (int x : v)
                {
                    dp[k + 1][x] += dp[k][u] / v.size();
                }
            }
        }
        for (int j = 0; j < sz; j++)
        {
            ans[j] *= (1 - dp[K][j]);
        }
    }

    double expectation = 0.0;
    for (int i = 0; i < sz; i++)
    {
        expectation += ans[i];
    }
    cout << fixed << setprecision(6) << expectation << endl;
}
