#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

void solve()
{
    ll m, n;
    cin >> m >> n;
    swap(n, m);
    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    vector<vector<ll>> dp(n + 1LL, vector<ll>(m + 1LL, (ll)-1));

    function<ll(ll, ll, ll, ll)> mem = [&](ll i, ll j, ll min_val, ll max_val)
    {
        if (i == n && j == m)
        {
            return 0LL; // Ensure that 0 is of type ll
        }
        if (dp[i][j] != -1LL)
        {
            return dp[i][j];
        }
        ll ans1 = LLONG_MIN, ans2 = LLONG_MIN;

        if (i < n)
        {
            ll new_min_val = min(min_val, a[i]);
            ll new_max_val = max(max_val, a[i]);
            ans1 = (new_max_val - new_min_val) + mem(i + 1, j, new_min_val, new_max_val);
        }
        if (j < m)
        {
            ll new_min_val = min(min_val, b[j]);
            ll new_max_val = max(max_val, b[j]);
            ans2 = (new_max_val - new_min_val) + mem(i, j + 1, new_min_val, new_max_val);
        }
        return dp[i][j] = max(ans1, ans2);
    };
    ll res = mem(0LL, 0LL, LLONG_MAX, LLONG_MIN); // Ensure initial values are of type ll
    cout << res << endl;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
