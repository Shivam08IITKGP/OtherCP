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
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    vector<int> p;
    p.push_back(0);
    f(i, 0, n)
    {
        cin >> a[i];
        if (a[i] & 1)
        {
            p.push_back(i + 1);
        }
    }
    int ans = 0;
    p.push_back(n + 1);
    for (int i = 1; i < p.size(); i++)
    {
        if (i + k < p.size())
            ans += (p[i] - p[i - 1]) * (p[i + k] - p[i + k - 1]);
        else
            break;
    }
    cout << ans << endl;
}

int main()
{
    FAST;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
