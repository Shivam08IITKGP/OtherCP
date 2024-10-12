void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    read(a);

    int l = *max_element(all(a)), r = accumulate(all(a), 0LL);
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        int cnt = 1, sum = 0;
        fr(i, n)
        {
            if (sum + a[i] > mid)
            {
                cnt++;
                sum = 0;
            }
            sum += a[i];
        }
        if (cnt <= k)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
}
