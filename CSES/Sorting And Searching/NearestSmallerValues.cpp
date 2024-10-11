void solve()
{
    int n;
    cin>>n;
    vi a(n);
    read(a);


    vi ans(n,0);
    stack<ii>s;

    s.push({a[n-1],n-1});
    per(i, n-2, 0)
    {
        if(s.empty())
        {
            s.push({a[i],i});
        }
        else
        {
            while(!s.empty() && s.top().F > a[i])
            {
                ans[s.top().S] = i+1;
                s.pop();
            }
            s.push({a[i],i});
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }

    


}
