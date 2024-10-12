void solve()
{
    int n;
    read(n);
    vector<pair<ii, int>> a(n);
    fr(i, n)
    {
        read(a[i].F.F, a[i].F.S);
        a[i].S = i;
    }
    vi ans1(n, 0), ans2(n, 0);
    sort(all(a), [](const pair<ii, int> c, const pair<ii, int> b)
         { if(c.F.F!=b.F.F) return c.F.F < b.F.F; return c.F.S>b.F.S; });

    set<ii> s;

    for (int i = 0; i < n; i++)
    {
        auto it = s.lower_bound({a[i].F.S, 0});
        if (it != s.end())
        {
            ans2[a[i].S] = 1;
        }
        s.insert({a[i].F.S, a[i].S});
    }
    s.clear();

    fr(i, n)
    {
        swap(a[i].F.F, a[i].F.S);
    }
    sort(all(a), [](const pair<ii, int> c, const pair<ii, int> b)
         { if(c.F.F!=b.F.F) return c.F.F < b.F.F; return c.F.S>b.F.S; });

    for (int i = 0; i < n; i++)
    {
        auto it = s.lower_bound({a[i].F.S, 0});
        if (it != s.end())
        {
            ans1[a[i].S] = 1;
        }
        s.insert({a[i].F.S, a[i].S});
    }
    fr(i, n)
    {
        cout << ans1[i] << " ";
    }
    cout << endl;
    fr(i, n)
    {
        cout << ans2[i] << " ";
    }
}
