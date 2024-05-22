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
    ll a, b, k;
    cin >> a >> b >> k;
    int moves = 0;
    //Brute Force
    //Applied reverse operations to get a from b

    while (b != a)
    {
        if (b % k == 0)
        {
            if (b / k >= a)
            {
                b = b / k;
                moves++;
            }
            else
            {
                moves += b - a;
                b = a;
            }
        }
        else
        {
            ll temp = min(b % k, b - a);
            b -= temp;
            moves += temp;
        }
    }
    cout << moves << endl;
}

int main()
{
    FAST;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
