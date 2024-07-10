#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string largestNumber(int K, vector<int>& cost) {
    // dp[i] will store the number we can form with cost i
    vector<string> dp(K + 1, "");
    
    for (int i = 0; i < 9; ++i) {
        for (int j = cost[i]; j <= K; ++j) {
            if (dp[j - cost[i]] != "" || j == cost[i]) {
                string candidate = dp[j - cost[i]] + to_string(i + 1);
                if (candidate.length() > dp[j].length() || (candidate.length() == dp[j].length() && candidate > dp[j])) {
                    dp[j] = candidate;
                }
            }
        }
    }
    
    return dp[K].empty() ? "IMPOSSIBLE" : dp[K];
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int K;
        cin >> K;
        
        vector<int> cost(9);
        for (int i = 0; i < 9; ++i) {
            cin >> cost[i];
        }
        
        cout << largestNumber(K, cost) << endl;
    }
    
    return 0;
}
