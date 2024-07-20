void solve()
{
    int n;
    cin>>n;
    vi a(n);
    read(a);
    int ans = 0;
    fr(i, n)
    {
        if(a[i]==0)
        {
            a[i]=-1;
        }
    }

    unordered_map<int, int>m;
    int sum = 0;
    m[0] = -1;
    for(int i=0;i<n;i++)
    {
        sum+= a[i];
        if(m.find(sum)!=m.end())
        {
            remax(ans, i - m[sum]);
        }
        else
        {
            m[sum] = i;
        }
    }
    cout<<ans<<endl;

}
