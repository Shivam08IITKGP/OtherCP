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
/*
The inner loop calculates the number of unique BSTs 
with n nodes by considering each value i as the root 
of the BST. The number of unique BSTs with n nodes 
is the sum of the products of the number of unique 
BSTs of the left and right subtrees. The left subtree
has i-1 nodes, and the right subtree has n-i nodes.
*/
