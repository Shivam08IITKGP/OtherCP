#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; ++i) cin >> s[i];
    string m; cin >> m;
    m = "#" + m;
    int sz = m.size();
    vector<bool> dp(sz, false);
    dp[0] = true;
    for(int i = 1; i < sz; ++i) 
        for(int j = max(0ll, i - 20); j < i; ++j) 
            for(int k = 0; k < n; ++k) if(dp[j] && m.substr(j + 1, i - j) == s[k]) dp[i] = true;
    cout << (dp[sz - 1] ? "YES" : "NO");
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int _TC = 0; cin >> _TC;
  for(int _ct = 1; _ct <= _TC; ++_ct) {
      solve(); cout << endl;
  }
}
