int nCr(int n, int r)
{
    // take mod as M
    if (r > n - r)
        r = n - r;
    int ans = 1;
    for (int i = 1; i <= r; i++)
    {
        ans = (ans * (n - r + i)) % M;
        ans = (ans * binpow(i, M - 2)) % M;
    }
    return (ans) % M;
}

void solve()
{
    int k;
    cin >> k;
    vi c(27);
    for (int i = 1; i <= 26; i++)
    {
        cin >> c[i];
    }
    vi dp(k + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= 26; i++)
    {
        vi tmp(k + 1, 0);

        for (int len = 1; len <= k; len++)
        {
            for (int ct = 1; ct <= min(c[i], len); ct++)
            {
                tmp[len] = (tmp[len] + (nCr(len, ct) * 1LL * dp[len - ct]) % M) % M;
            }
        }

        for (int len = 1; len <= k; len++)
        {
            dp[len] = (dp[len] + tmp[len]) % M;
        }
    }
    int sum = 0;
    rep(i, 1, k)
    {
        sum = (sum + dp[i]) % M;
    }
    cout << sum << endl;
}
