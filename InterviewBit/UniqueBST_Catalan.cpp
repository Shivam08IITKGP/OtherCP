int Solution::numTrees(int A) 
{
    vector<int>dp(A+1,0);
    dp[0] = 1;
    dp[1] = 1;
    for(int n=2;n<=A;n++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[n]+= dp[j-1]*dp[n-j];
        }
    }
    return dp[A];
    
}
