int Solution::anytwo(string A) 
{
    int n=A.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(A[i-1]==A[j-1]&&i!=j)
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    if(dp[n][n]>=2)
    {
        return 1;
    }
    return 0;
}

// https://www.interviewbit.com/problems/repeating-subsequence/
