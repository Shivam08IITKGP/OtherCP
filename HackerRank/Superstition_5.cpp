void solve()
{
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;

    stack<pair<char, int>> s;
    int count_curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.empty() or a[i] != s.top().F)
        {
            s.push({a[i], 1});
        }
        else
        {
            s.push({a[i], s.top().S + 1});
        }
        while (s.top().S >= k and !s.empty())
        {
            fr(i, k)
                s.pop();
        }
    }
    string ans;
    while (!s.empty())
    {
        ans += s.top().F;
        s.pop();
    }
    reverse(all(ans));
    cout << ans << endl;
}
