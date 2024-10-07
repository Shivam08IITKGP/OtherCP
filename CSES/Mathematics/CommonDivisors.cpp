void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    read(a);

    vi cnt(1e6 + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cnt[a[i]]++;
    }
    int maxi = *max_element(a.begin(), a.end());

    for (int i = maxi; i >= 2; i--)
    {
        int c = 0;
        for (int j = i; j <= maxi; j += i)
        {
            c += cnt[j];
            if (c >= 2)
            {
                cout << i;
                return;
            }
        }
    }
    cout << 1;
    return;
}
