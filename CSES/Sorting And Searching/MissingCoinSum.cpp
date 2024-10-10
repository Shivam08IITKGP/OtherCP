void solve()
{
    int n;
    cin >> n;
    vi x(n);
    read(x);

    sort(all(x));
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (x[i] > ans)
        {
            cout << ans;
            return;
        }
        ans += x[i];
    }
    cout << ans;
    return;
}
