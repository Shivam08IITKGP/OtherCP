// link -> https://www.codechef.com/problems/SUMMODE
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi a(n);
    rep(i, 0, s.size() - 1)
    {
        if (s[i] - '0' == 0)
        {
            a[i] = -1;
        }
        else
            a[i] = 1;
    }
    map<int, int> m;
    vi prefix(s.size() + 1, 0);
    int ans = n * (n + 1) / 2;
    rep(i, 1, s.size())
    {
        prefix[i] = prefix[i - 1] + a[i - 1];
        if(prefix[i]==0) ans++;
        ans += m[prefix[i]]++;
    }
    cout << ans << endl;
}
