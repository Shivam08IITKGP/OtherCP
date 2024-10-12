void solve()
{
    int n, m;
    cin >> n >> m;
    vi a(n + 1);
    read1(a);

    vi ind(n + 2);
    ind[n + 1] = n + 1;
    for (int i = 1; i <= n; i++)
    {
        ind[a[i]] = i;
    }
    int l = 1;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (l > ind[i])
        {
            ans++;
        }
        l = ind[i];
    }

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        // x--;
        // y--;
        int r = a[x], s = a[y];
        swap(a[x], a[y]);

        if (ind[r - 1] <= ind[r] and ind[r - 1] > y)
            ans++;
        if (ind[r - 1] > ind[r] and ind[r - 1] <= y)
            ans--;
        if (ind[r] <= ind[r + 1] and ind[r + 1] < y)
            ans++;
        if (ind[r] > ind[r + 1] and ind[r + 1] >= y)
            ans--;

        ind[r] = y;

        if (ind[s - 1] <= ind[s] and ind[s - 1] > x)
            ans++;
        if (ind[s - 1] > ind[s] and ind[s - 1] <= x)
            ans--;
        if (ind[s] <= ind[s + 1] and ind[s + 1] < x)
            ans++;
        if (ind[s] > ind[s + 1] and ind[s + 1] >= x)
            ans--;

        ind[s] = x;
        cout << ans << endl;
    }
}
