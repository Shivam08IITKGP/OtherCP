int Solution::maxPathSum(TreeNode* root) 
{
    int ans = INT_MIN; // Initialize ans to INT_MIN to handle negative values correctly.
    
    // Lambda function to perform DFS traversal.
    function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int
    {
        if (!node) return 0; // If the node is null, return 0.
        
        // Recursively get the maximum path sum for the left and right subtrees.
        int l = max(0, dfs(node->left)); // Only consider positive contributions.
        int r = max(0, dfs(node->right)); // Only consider positive contributions.
        
        // Update the maximum path sum (including the current node).
        ans = max(ans, l + r + node->val);
        
        // Return the maximum path sum including the current node and one of its subtrees.
        return node->val + max(l, r);
    };
    
    dfs(root); // Start the DFS traversal from the root.
    return ans; // Return the final maximum path sum.
}
