void solve()
{
    int n, k;
    cin >> n >> k;
    vi p(k);
    read(p);
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(p[i]);
    }
    string ans;
    for (int i = 1; i <= n; i++)
    {
        if (s.find(i) != s.end())
        {
            ans += 'W';
        }
        else
        {
            bool flag = false;
          // Note using for(auto it: s) here will lead to tle here, so use k iterations instead
            for (int j = 0; j < k; j++)
            {
                if (i - p[j] > 0 and ans[i - p[j] - 1] == 'L')
                {
                    flag = true;
                    ans += 'W';
                    break;
                }
            }
            if (!flag)
            {
                ans += 'L';
            }
        }
    }
    cout << ans ;
}
