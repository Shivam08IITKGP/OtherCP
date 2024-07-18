void solve()
{
    int n;
    cin>>n;
    vi blue(n-1), red(n-1);
    read(red);
    read(blue);
    
    int blueCost;
    cin>>blueCost;
    
    vi dp_red(n, 0), dp_blue(n, 0);
    dp_blue[0] = blueCost;
    cout<<0<<" ";

    for(int i=1;i<n;i++)
    {
        dp_red[i] = min(dp_red[i-1]+red[i-1],dp_blue[i-1]+red[i-1] );
        dp_blue[i] = min(dp_red[i-1]+blue[i-1]+blueCost, dp_blue[i-1]+blue[i-1]);
        cout<<min(dp_red[i], dp_blue[i])<<" ";
    }
    cout<<endl;
     

}
