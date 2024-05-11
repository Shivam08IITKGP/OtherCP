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

void solve()
{
    int n, k;
    cin >> n >> k;
    ll prod = 1;
    int ans = 0;
    f(i, 0, n)
    {
        ll x;
        cin >> x;
        if(x==1) 
        continue;
        if (prod * x > k)
        {
            prod = x;
            // ans++;
            // The below step is most important
            // The case of a[0] is being added two times if the first element is greater than k
            // Example 
            /*
            5 6
            7 1 4 1 3 2 => should give answer 3
            5 6
            6 1 4 1 3 2 => should give answer 2

            In the first test case, 7 is getting added two times, as final prod= a[0] for i=0
            and initial prod=a[0] for i=2
            Hence if(i) condition is must
            */
            if (i)
            {
                ans++;
            }
        }
        else
        {
            prod *= x;
        }
    }
    cout << ans + 1 << endl;
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
