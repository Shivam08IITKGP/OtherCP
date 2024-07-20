#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    
    int ans = 0;
    
    // Iterate over all 60 bits (since A[i] < 2^60)
    for(int bit = 0; bit < 60; ++bit) {
        int count_1 = 0;
        
        // Count number of 1s at the current bit position
        for(int i = 0; i < n; ++i) {
            if(a[i] & (1LL << bit)) {
                count_1++;
            }
        }
        
        // Number of 0s is total elements minus number of 1s
        int count_0 = n - count_1;
        
        // Each pair of 1 and 0 contributes (1 << bit) to the XOR sum
        int bit_contribution = (count_1 * count_0) % MOD;
        bit_contribution = (bit_contribution * (1LL << bit)) % MOD;
        
        // Add this contribution to the answer
        ans = (ans + bit_contribution) % MOD;
    }
    
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
