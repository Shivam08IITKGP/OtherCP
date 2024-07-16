void solve()
{
    int n, k;
    cin>>n>>k;
    vector<vector<int>>dp(n+1, vector<int>(k+1, 0));

    dp[0][0] = 1;
    int sum = 1;
    for(int i=1;i<=n;i++)
    {
        dp[i][0] = (sum*21)%N;
        sum = dp[i][0];
        for(int j=1;j<=k;j++)
        {
            if(j>i)
            {
                dp[i][j] = 0;
            }
            else if(i==j)
            {
                dp[i][j] = binpow(5, i, N);
            }
            else
            {
                dp[i][j] = dp[i-1][j-1]*5;
            }
            dp[i][j]%=N;
            sum+=dp[i][j];
            sum%=N;
        }        
    }
    cout<<sum<<endl;
}
