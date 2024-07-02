int Solution::solve(vector<int> &A, int B) 
{
    int n = A.size();
    if(n==0 or B==0)
    {
        return 0;
    }
    B = min(B,n);
    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(B+1, vector<int>(2,0)));
    
    for(int i=0;i<=n;i++)
    {
        for(int j= 0;j<=B;j++)
        {
            if(i==0 or j==0)
            {
                dp[i][j][0] = 0;
                dp[i][j][1] = INT_MIN;
            }
            else
            {
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+A[i-1]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-A[i-1]);
            }
        }
    }
    int ans = 0;
    for(int i=0;i<=B;i++)
    {
        ans = max(ans, dp[n][i][0]);
    }
    return ans;
}
//https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stock-atmost-b-times/
