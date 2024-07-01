int Solution::minCut(string A) 
{
    int n = A.size();
    vector<vector<bool>>isPalindrome(n, vector<bool>(n,false));
    for(int i=0;i<n;i++)
    {
        isPalindrome[i][i]= 1;
    }    
    for(int len = 2;len<=n;len++)
    {
        for(int l= 0;l<n;l++)
        {
            int r= l+len-1;
            if(r>=n)
            {
                break;
            }
            if(len==2)
            {
                if(A[l]==A[r])
                {
                    isPalindrome[l][r]=1;
                }                               
            }
            else if(A[l]==A[r] and isPalindrome[l+1][r-1])
            {
                isPalindrome[l][r]=1;
            }
        }
    }
    
    vector<int>cuts(n,0);
    for(int i=0;i<n;i++)
    {
        int minCuts= i;
        for(int j=0;j<=i;j++)
        {
            if(isPalindrome[j][i])
            {
                minCuts = (j==0)?0:min(minCuts, 1+cuts[j-1]);
            }
        }
        cuts[i] = minCuts;
    }
    return cuts[n-1];
}
