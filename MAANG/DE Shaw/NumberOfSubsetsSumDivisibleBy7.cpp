#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(7, 0);
    dp[0] = 1;  // There's always one subset with sum 0 (the empty subset)

    for (int i = 0; i < n; i++) {
        vector<int> new_dp = dp;  // Make a copy of the current state of dp
        for (int j = 0; j < 7; j++) {
            int new_sum = (j + arr[i]) % 7;
            new_dp[new_sum] = (new_dp[new_sum] + dp[j]) % MOD;
        }
        dp = new_dp;
    }

    // The result is the number of subsets whose sum is divisible by 7
    cout << (dp[0] - 1 + MOD) % MOD << endl;  // Subtract 1 to exclude the empty subset
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
