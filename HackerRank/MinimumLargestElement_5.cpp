void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    rep(i, 1, n)
    {
        cin >> a[i];
    }

    int l = *max_element(all(a));
    int r = 1e18;
    int ans = -1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        int cnt = 0;
        for (int i = 1; i <= n and cnt < k; i++)
        {
            cnt += (mid - a[i]) / i;
        }
        if (cnt >= k)
        {
            //Here we are adding up every element mid-a[i]/i because 
            //If the cnt exceeds k then it will break
            //Also it covers the condition of only one element to all elements 
            //becoming equal to k (because cnt can loop out anytime)
            //we are going backwards as a to check if even lower mid is possible or not
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout<<ans<<endl;
}
