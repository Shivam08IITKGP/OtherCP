void solve()
{

    int n;
    cin >> n;
    vi a(n);
    read(a);
    vi b(n);
    read(b);
    vi pos(n + 1);
    fr(i, n)
    {
        pos[a[i]] = i;
    }
    vi v;
    fr(i, n)
    {
        v.pb(pos[b[i]]);
    }

    vi ma(n + 1);
    int ans = 0;
    fr(i, n)
    {
        ma[v[i]] = ma[v[i] - 1] + 1;
        remax(ans, ma[v[i]]);
    }
    cout << n - ans << endl;
}
