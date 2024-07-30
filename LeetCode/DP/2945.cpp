class Solution {
public:    
    int findMaximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n+1); // 1-indexed vector
        pref[0] = 0;
        for(int i = 0; i < n; i++) pref[i+1] = pref[i] + nums[i];
        
        vector<pair<int, long long>> memo(n+2);
        memo[0].first = 1;
        for(int i = 1; i <= n; i++){
            memo[i] = max(memo[i], memo[i-1]);
            int idx = lower_bound(pref.begin(), pref.end(), 2*pref[i] - memo[i].second) - pref.begin();
            memo[idx] = max(memo[idx], {memo[i].first+1, pref[i]});
        }
        return memo[n].first;
    }
};
