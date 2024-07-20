void solve()
{
    int n;
    cin>>n;
    vi a(n);
    read(a);

    vii vec;
    for(int i=0;i<n;i++)
    {
        vec.pb({a[i], i});
    }

    reverse(all(a));
    if(is_sorted(all(a)))
    {
        cout<<-1<<endl;
        return;
    }

    sort(all(vec));

    int minIndex = vec[0].S;
    int ans = 0;
    for(int i=1;i<n;i++)
    {
        if(vec[i].S>minIndex)
        {
            ans = max(ans, vec[i].S - minIndex);
        }
        minIndex = min(minIndex, vec[i].S);
    }
    cout<<ans<<endl;
}
