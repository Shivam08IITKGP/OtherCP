class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int N = n / 2;
        vector<vector<int>> left(N+1), right(N+1);
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // Finding the subarrays
        for (int i = 0; i < (1 << N); i++) {
            int sz = 0, sum1 = 0, sum2 = 0;
            for (int bit = 0; bit < N; bit++) {
                if ((i >> bit) & 1) {
                    sz++;
                    sum1 += nums[bit];
                    sum2 += nums[bit + N];
                }
            }
            left[sz].push_back(sum1);
            right[sz].push_back(sum2);
        }

        // Sorting the right subarrays for binary search
        for (int i = 0; i <= N; i++) {
            sort(right[i].begin(), right[i].end());
        }

        int ans = abs(sum - 2 * left[N][0]);  // Initial answer

        // Finding the minimum difference
        for (int i = 0; i <= N; i++) {  // Ensure it goes up to N
            for (auto it : left[i]) {
                int b = (sum - 2 * it) / 2;
                int sz = N - i;
                auto itr = lower_bound(right[sz].begin(), right[sz].end(), b);
                if (itr != right[sz].end()) {
                    ans = min(ans, abs(sum - 2 * (it + *itr)));
                }
            }
        }
        return ans;
    }
};
