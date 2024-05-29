https://www.geeksforgeeks.org/problems/geek-and-its-game-of-coins4043/1

class Solution {
  public:
    int findWinner(int n, int x, int y) 
    {
        // code here
        vector<int>dp(n+1,0);
        for(int i=0;i<=n;i++)
        {
            if(dp[i]==0)
            {
                if(i<=n-1)
                dp[i+1]=1;
                if(i<=n-x)
                dp[i+x]=1;
                if(i<=n-y)
                dp[i+y]=1;
            }
        }
        return dp[n];
        
    }
};
