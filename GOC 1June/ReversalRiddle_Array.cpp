void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> m;
    int ans = 0;
    rep(i, 1, n)
    {
        cin >> a[i];
        ans += i - m[a[i]] - 1;
        m[a[i]]++;
    }
    cout << ans + 1 << endl;
}
