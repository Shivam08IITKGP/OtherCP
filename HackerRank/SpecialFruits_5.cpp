void solve()
{
    int n;
    cin >> n;
    vector<ii> p;
    for (int i = 0; i < n; i++)
    {
        int v, x;
        cin >> v >> x;
        p.pb({v + x, v - x});
    }
    sort(all(p));
    vector<int> points;

    for (int i = 0; i < n; i++)
    {
        if (points.empty())
        {
            points.pb(p[i].F);
        }
        else
        {
            if (points.back() < p[i].S)
            {
                points.pb(p[i].F);
            }
        }
    }
    cout << points.size() << endl;
    // cout<<points<<endl;
    for (auto &x : points)
    {
        cout << x << " ";
    }
    cout << endl;
}
