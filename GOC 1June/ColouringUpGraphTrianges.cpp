void solve()
{
    int n, k;
    cin >> n >> k;
    // graph g(n + 1);
    vi y(n + 1);
    vi b(n + 1);
    rep(i, 1, k)
    {
        int u, v;
        cin >> u >> v;
        y[u]++;
        y[v]++;
    }
    rep(i, 1, n)
    {
        b[i] = n - 1 - y[i];
    }
    int ans = 0;

    // there will be three nodes in a triangle
    // two nodes have the two different colour edges
    // and third node have the same colour edges
    rep(i, 1, n)
    {
        ans += y[i] * b[i];
    }
    ans = (ans / 2) % MOD;
    cout << ans << endl;
}
