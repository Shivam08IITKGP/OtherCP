int Solution::numDistinct(string A, string B) 
{
    int n = A.size();
    int m = B.size();
    vector<int>dp(m+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j = m-1;j>=0;j--)
        {
            if(A[i]==B[j])
            {
                dp[j+1]+= dp[j];
            }
        }        
    }
    return dp[m];
}
