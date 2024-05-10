#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define v vector
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

bool check(ll a, ll b, ll i)
{
    ll temp = 1;
    while (i--)
    {
        temp *= a;
        if (temp > b)
        {
            // checking a[j]^k > a[i] where k is between 1 to (i+1)
            return false;
        }
    }
    return true;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            ans += n;
        }
    }
  //Checking till 30 because 2^30 is just greater than 1e9
  //So there can be only 1 number that can contribute to ans that is 1
    f(i, 0, min((ll)30, n))
    {
        f(j, 0, n)
        {
            if (a[j] != 1)
            {
                ans += check(a[j], a[i], i + 1);
            }
        }
    }
    cout << ans << endl;
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
