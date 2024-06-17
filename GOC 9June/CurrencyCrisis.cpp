#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long 
#define pb push_back
#define pk pop_back
#define fr first
#define sc second
#define endl '\n'

const ll mod = 1000000007, mod2 = 998244353;
const ll INF = 1e18;

void solve(){
    int n;
    cin >> n;
    int ga,sa,pa;
    int gb,sb,pb;
    cin >> ga >> sa >> pa;
    cin >> gb >> sb >> pb;
    int profit;
    vector<int>dp(n + 1, 0);
    for(int i = 1; i < n + 1; ++i){
        dp[i] = dp[i - 1];
        profit = 0;
        if(ga <= i){
            profit = max(dp[i], dp[i - ga] + gb - ga);
        }
        if(sa <= i){
            profit = max(profit, dp[i - sa] + sb - sa);
        }
        if(pa <= i){
            profit = max(profit, dp[i - pa] + pb - pa);
        }
        dp[i] = max(profit, dp[i]);
    }
    int profitA = dp[n];
    n += profitA;
    dp.assign(n + 1, 0);
    for(int i = 1; i < n + 1; ++i){
        dp[i] = dp[i - 1];
        profit = 0;
        if(gb <= i){
            profit = max(dp[i], dp[i - gb] + ga - gb);
        }
        if(sb <= i){
            profit = max(profit, dp[i - sb] + sa - sb);
        }
        if(pb <= i){
            profit = max(profit, dp[i - pb] + pa - pb);
        }
        dp[i] = max(profit, dp[i]);
    }
    cout << profitA + dp[n] << endl;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt = 1; //cin >> tt;
    while(tt--){
        solve(); 
    }
    return 0;
}
