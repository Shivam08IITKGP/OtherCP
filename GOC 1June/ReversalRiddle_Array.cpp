void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> m;
    int ans = 0;
    // We have to count the number of pairs l,r such that a[l]==a[r],
    // l<r because reversing the substring l+1, r-1 be will give the same
    // string as reversing l,r.
    rep(i, 1, n)
    {
        cin >> a[i];
        // We are adding the subsegments that start from i to the left
        // i.e. [j,i] where j belongs to [1,i-1]
        ans += i - m[a[i]] - 1;
        m[a[i]]++;
    }
    cout << ans + 1 << endl;
}
