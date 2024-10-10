void solve()
{
    int n;
    cin >> n;
    vi a(n);
    read(a);

    vi indices(n + 1);
    for (int i = 0; i < n; i++)
    {
        indices[a[i]] = i;
    }
    int ans = 1;
    for (int num = 1; num < n; num++)
    {
        if (indices[num] > indices[num + 1])
        {
            ans++;
        }
    }
    cout<<ans;
}
