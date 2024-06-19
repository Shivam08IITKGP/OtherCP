void solve()
{
    int n, m;
    read(n, m);
    if (m == 0)
    {
        cout << n * (n + 1) / 2 << endl;
        return;
    }
    vi a(m);
    vi b(m);
    read(a);
    read(b);
    vi next(n + 1, N);
    int mn = N;
    for (int i = 0; i < m; i++)
    {
        next[min(a[i], b[i])] = min(next[min(a[i], b[i])], max(a[i], b[i]));
    }

    int ans = 0;
    int curr_next;
    for (int i = n; i >= 1; i--)
    {
        curr_next = min(mn, next[i]);
        if (curr_next == N)
        {
            ans += n - i + 1;
        }
        else
        {
            ans += curr_next - i;
        }
        remin(mn, next[i]);
    }
    cout << ans << endl;
}
