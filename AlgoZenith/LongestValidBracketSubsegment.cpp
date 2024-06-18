#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define per(i, start, end) for (ll i = start; i >= end; i--)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define F first
#define S second
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;
#define int long long

void solve()
{
    int n;
    string s;
    cin >> s;
    n = s.size();
    stack<int> st;
    int dp[n];
    memset(dp, -1, sizeof(dp));
    fr(i, n)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            if (!st.empty())
            {
                int t = st.top();
                st.pop();
                if (t - 1 >= 0 and s[t - 1] == '(' and dp[t - 1] != -1)
                {
                    dp[i] = dp[t - 1];
                }
                else
                {
                    dp[i] = t;
                }
            }
        }
    }
    
    int ans = 0;
    fr(i, n)
    {
        if (dp[i] != -1)
        {
            ans = max(ans, i - dp[i] + 1);
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    FAST;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
