void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> peeps(n);
    vector<int> apps(m);
    read(peeps);
    read(apps);
    sort(all(peeps));
    sort(all(apps));
    int ans = 0;
    int i = 0, j = 0;
    while (i < n and j < m)
    {
        if (abs(peeps[i] - apps[j]) <= k)
        {
            ans++;
            i++;
            j++;
        }
        else if (peeps[i] < apps[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << ans;
}

// Time Complexity = O(nlogn + mlogm)
