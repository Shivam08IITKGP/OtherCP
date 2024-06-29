//link - https://www.codechef.com/problems/BREAKSTRING?tab=statement
void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    vi z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    vi z_r(n, 0);
    reverse(all(s));
    // cout << s << endl;
    l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
            z_r[i] = min(r - i, z_r[i - l]);
        while (i + z_r[i] < n && s[z_r[i]] == s[i + z_r[i]])
            z_r[i]++;
        if (i + z_r[i] > r)
        {
            l = i;
            r = i + z_r[i];
        }
    }
    // cout << z_r << endl;
    // cout << z << endl;
    int ans = 0;
    fr(i, n)
    {
        if (z[i] >= i)
        {
            if (2 * i == n)
            {
                ans++;
            }
            else if (n > 2 * i)
            {
                int rem_len = n - 2 * i;
                if (rem_len % 2 == 0)
                {
                    if (z_r[rem_len / 2] >= rem_len / 2)
                    {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
