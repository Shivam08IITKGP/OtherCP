void buildST(vi &a, graph &dp, int l, int r, int index)
{
    if(l==r)
    {
        dp[index][0] = 0;
        dp[index][1] = a[l];
        dp[index][2] = a[l];
        dp[index][3] = a[l];
        return;
    }
    int mid = (l+r)>>1;
    buildST(a, dp, l, mid, 2*index+1);
    buildST(a, dp, mid+1, r, 2*index+2);

    dp[index][0] = max({dp[2*index][0]+ dp[2*index+1][0], dp[2*index][2]+dp[2*index+1][0], dp[2*index][0]+ dp[2*index+1][1]});
    dp[index][1] = max({dp[2*index][1]+ dp[2*index+1][0], dp[2*index][1]+dp[2*index+1][1], dp[2*index][3]+ dp[2*index+1][0]});
    dp[index][2] = max({dp[2*index][0]+ dp[2*index+1][2], dp[2*index][2]+dp[2*index+1][2], dp[2*index][0]+ dp[2*index+1][3]});
    dp[index][2] = max({dp[2*index][1]+ dp[2*index+1][2], dp[2*index][1]+dp[2*index+1][3], dp[2*index][3]+ dp[2*index+1][2]});
}

void updateST(int index, int l, int r, int val, int update_index, graph &dp)
{
    if(l==r)
    {
        dp[index][0] = 0;
        dp[index][1] = val;
        dp[index][2] = val;
        dp[index][3] = val;
        return;
    }
    int mid = (l+r)>>1;
    if(l<=update_index and update_index<=mid)
    {
        updateST(2*index, l, mid, val, update_index, dp);
    }
    else
    {
        updateST(2*index+1, mid+1, r,val, update_index, dp);
    }

    dp[index][0] = max({dp[2*index][0]+ dp[2*index+1][0], dp[2*index][2]+dp[2*index+1][0], dp[2*index][0]+ dp[2*index+1][1]});
    dp[index][1] = max({dp[2*index][1]+ dp[2*index+1][0], dp[2*index][1]+dp[2*index+1][1], dp[2*index][3]+ dp[2*index+1][0]});
    dp[index][2] = max({dp[2*index][0]+ dp[2*index+1][2], dp[2*index][2]+dp[2*index+1][2], dp[2*index][0]+ dp[2*index+1][3]});
    dp[index][2] = max({dp[2*index][1]+ dp[2*index+1][2], dp[2*index][1]+dp[2*index+1][3], dp[2*index][3]+ dp[2*index+1][2]});

}

class Solution {
  public:
    int
    maximumSumSubsequence(vector<int> &nums, vector<vector<int>> &queries) {
        int                 n      = nums.size();
        int                 q      = queries.size();
        int                 result = 0;
        vector<vector<int>> dp(4 * n, vector<int>(4));
        for (int t = 0; t < q; t++) {
            nums[queries[t][0]] = queries[t][1];

            int left  = 0;
            int right = nums.size() - 1;
            int n     = nums.size();
            if (t == 0) {
                buildST(nums, dp, 1, left, right);
            } else {
                updateST(1, left, right, queries[t][1], queries[t][0], dp);
            }
            int max_v = 0;
            for (int i = 0; i < 4; i++) {
                max_v = max(dp[1][i], max_v)% (1000000000 + 7);
            }
            result = (result + max_v) % (1000000000 + 7);
        }
        return result;
    }
};
