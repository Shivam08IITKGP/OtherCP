void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    read(a);
    vector<ii> p;
    stack<ii> s;
    fr(i, n + 1)
    {
        if (a[i])
        {
            p.pb({max(0LL, i - a[i]), min(i + a[i], n)});
        }
    }
    s.push({INT_MIN, 0});
    for (auto e : p)
    {
        auto [l, r] = e;
        if (l <= s.top().S and r > s.top().S)
        {
            while (l <= s.top().F)
            {
                s.pop();
            }
            s.push({s.top().S, r});
        }
    }
    cout << ((s.top().S < n) ? -1 : s.size() - 1) << endl;
}
