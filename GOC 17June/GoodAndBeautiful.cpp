void solve()
{
    int n;
    cin >> n;
    vi a(n);
    read(a);
    vi freq(200005, 0);
    vi ans(200005, 0);
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }
    ans[1]= freq[1];
    ans[0]= 0;
    for (int i = 2; i <= 2e5; i++)
    {
        remax(ans[i], max(ans[i - 1], freq[i] * i + ans[i - 2]));
    }
    cout << ans[200000] << endl;
}
