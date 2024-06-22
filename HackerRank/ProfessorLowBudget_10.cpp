void solve()
{
    int n;
    cin>>n;
    vi s(n),u(n);

    read(s);
    read(u);

    int ans=0;

    int min_ind_s=min_element(s.begin(),s.end())-s.begin();
    int min_ind_u=min_element(u.begin(),u.end())-u.begin();

    fr(i,n)
    {
        if(i==min_ind_s || i==min_ind_u)continue;
        ans+=min(s[i]*u[min_ind_u],u[i]*s[min_ind_s]);
        ans%=N;
    }

    if(min_ind_s!=min_ind_u)
    {
        ans+=s[min_ind_s]*u[min_ind_u];
        ans%=N;
    }

    cout<<ans;
}
