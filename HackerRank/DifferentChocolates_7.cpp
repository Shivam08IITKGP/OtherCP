vi ans(V / 2, 0);
void calc()
{
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 2; i < V / 2; i++)
    {
        ans[i] = (ans[i - 1] + (binpow(i, N - 2, N)) % N) % N;
    }
}
void solve()
{
    int n;
    cin >> n;
    fr(i, n)
    {
        int x;
        cin >> x;
    }
    cout << ans[n] << endl;
   
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    calc();
    while (t--)
    {
        solve();
    }
}
