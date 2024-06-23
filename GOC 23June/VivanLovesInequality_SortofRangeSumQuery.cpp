void solve()
{
    int n;
    cin >> n;
    vi a(n);
    read(a);
    int max_a = *max_element(all(a));

    map<int, int> ans;
    int fans = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = a[i];
        while (temp > 1)
        {
            ans[temp]--;
            temp = (temp + 1) / 2;
            fans++;
        }
        temp = a[i];
        while (temp <= max_a)
        {
            ans[temp + 1]++;
            temp *= 2;
        }
    }
    int temp = fans;
    for (auto it : ans)
    {
        temp += it.S;
        fans = min(fans, temp);
    }
    cout << fans << endl;
}
