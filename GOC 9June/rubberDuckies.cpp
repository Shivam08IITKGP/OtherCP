void solve()
{
    int n, q;
    cin >> n >> q;
    vii a(n);
    fr(i, n)
    {
        cin >> a[i].F;
        a[i].S = i;
    }
    sort(all(a));
    vi ind(n);
    vi b(n);
    b[0] = a[0].F;
    for (int i = 1; i < n; i++)
    {
        b[i] = a[i].F + b[i - 1];
    }
    fr(i, n)
    {
        ind[a[i].S] = i;
    }
    while (q--)
    {
        int k, bal;
        read(k, bal);
        vi bad(k);
        fr(i, k)
        {
            int x;
            cin >> x;
            bad[i] = ind[x - 1];
        }
        sort(all(bad));
        bad.pb(n);
        int curr_pos = 0;
        int ans = 0;
        for (int i = 0; i <= k; i++)
        {
            auto it = upper_bound(b.begin(), b.begin() + bad[i], bal);
            if (it > b.begin() + curr_pos)
            {
                remax(ans, it - b.begin() - i);
            }
            if (i != k)
            {
                bal += a[bad[i]].F;
                curr_pos = bad[i];
            }
        }
        cout << ans << " ";
    }
    cout << endl;
}
