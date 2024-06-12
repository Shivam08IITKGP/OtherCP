void solve()
{
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vi occ(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        occ[a[i]]++;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += occ[i] * (occ[i] + 1) / 2;
    }

    while (q--)
    {
        int p, x;
        cin >> p >> x;
        p--; 
        int old_val = a[p];
        ans -= occ[old_val] * (occ[old_val] + 1) / 2;
        occ[old_val]--;
        ans += occ[old_val] * (occ[old_val] + 1) / 2;

        
        ans -= occ[x] * (occ[x] + 1) / 2;
        occ[x]++;
        ans += occ[x] * (occ[x] + 1) / 2;

        
        a[p] = x;

        cout << ans << endl;
    }
}
