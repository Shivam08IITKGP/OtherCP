#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

signed main() {
   IOS
   int t;
   cin >> t;
   while(t--) {
       int n;
       string s;
       cin >> n >> s;
       int a[n];
       for (int i = 0; i < n; ++i) {
           cin >> a[i];
       }
       int dp[4] = {0};
       for (int i = 0; i < n; ++i) {
           if(s[i] == 'h') dp[0] += a[i];
           else if (s[i] == 'a') dp[1] = min(dp[0], dp[1] + a[i]);
           else if (s[i] == 'r') dp[2] = min(dp[1], dp[2] + a[i]);
           else if (s[i] == 'd') dp[3] = min(dp[2], dp[3] + a[i]);
       }
       cout << dp[3] << "\n";
   }
   return 0;
}
