int fact[1005], fact_inv[1005];

int binpow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * 1LL * a) % M;
        a = (a * 1LL * a) % M;
        b >>= 1;
    }
    return ans;
}

int nCr(int n, int r)
{
    if (r == 0 || n == r)
        return 1;

    int nume = fact[n];
    int deno = (fact_inv[r] * 1LL * fact_inv[n - r]) % M;
    return (nume * 1LL * deno) % M;
}
void solve()
{
    int k;
    cin >> k;
    fact[0] = fact_inv[0] = 1;
    for (int i = 1; i <= k; i++)
    {
        fact[i] = (i * 1LL * fact[i - 1]) % M;
        fact_inv[i] = binpow(fact[i], M - 2);
    }
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
