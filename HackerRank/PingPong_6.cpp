ll binpow(ll b, ll p, ll m)
{
    ll ans = 1;
    while (p)
    {
        if (p & 1)
            ans = ans * b % m;
        b = b * b % m;
        p >>= 1;
    }
    return ans;
}

vi invs(N), fact(N), ifact(N);

void precompute()
{
    fact[0] = ifact[0] = invs[1] = 1;
    for (int i = 2; i < N; ++i)
        invs[i] = invs[MOD % i] * (MOD - MOD / i) % MOD;
    for (int i = 1; i < N; ++i)
    {
        fact[i] = fact[i - 1] * i % MOD;
        ifact[i] = ifact[i - 1] * invs[i] % MOD;
    }
}

int nCr(int n, int r)
{
    if (r > n || r < 0)
        return 0;
    return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

void solve()
{
    int n, x, y;
    read(n, x, y);
    if (x > y)
        swap(x, y);
    if (y == n && x < n - 1)
    {
        cout << nCr(n - 1 + x, x) << endl;
    }
    else if (y - x == 2 && y > n)
    {
        cout << nCr(2 * n - 2, n - 1) * 2 % MOD << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    precompute();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
