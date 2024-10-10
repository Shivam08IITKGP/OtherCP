void solve()
{
    int n, m;
    cin >> n >> m;
    vi h(n), t(m);
    read(h);
    read(t);

    vi ans(m, -1);

    multiset<int> s(all(h));
    for(int i = 0;i<m;i++)
    {
        auto it = s.upper_bound(t[i]);
        if(it!=s.begin())
        {
            it--;
            ans[i] = *it;
            s.erase(it);            
        }
    }

    for (int i = 0; i < m; i++)
    {
        cout << ans[i] << endl;
    }
}
