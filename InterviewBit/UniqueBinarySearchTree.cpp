/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// This function should be declared outside the Solution class
vector<TreeNode*> solve(int start, int end) 
{
    vector<TreeNode*> res;
    if (start > end) {
        res.push_back(NULL);
        return res;
    }
    for (int i = start; i <= end; i++) {
        vector<TreeNode*> leftsubtree = solve(start, i - 1);
        vector<TreeNode*> rightsubtree = solve(i + 1, end);

        for (auto l : leftsubtree) {
            for (auto r : rightsubtree) {
                TreeNode* root = new TreeNode(i);
                root->left = l;
                root->right = r;
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode*> Solution::generateTrees(int A) {
    if (A == 0) return {};
    return solve(1, A);
}
