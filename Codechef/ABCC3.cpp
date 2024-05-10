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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    vector<int> bpos;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'b')
        {
            count++;
            bpos.push_back(i);
        }
    }
    if (count == 0)
    {
        cout << 0 << endl;
        return;
    }
    vector<int> counta(n, 0), countc(n, 0);
    if (s[0] == 'a')
    {
        counta[0] = 1;
    }
    if (s[0] == 'c')
    {
        countc[0] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        if (s[i] == 'a')
        {
            counta[i] = counta[i - 1] + 1;
            countc[i] = countc[i - 1];
        }
        else if (s[i] == 'b')
        {
            counta[i] = counta[i - 1];
            countc[i] = countc[i - 1];
        }
        else
        {
            countc[i] = countc[i - 1] + 1;
            counta[i] = counta[i - 1];
        }
    }
    //prefixa bpos.back and suffixc bpos.front
    //It is always valid ans 
    // it also covers the case of count of b=1
    int ans = min(counta[bpos.back()], countc[n - 1] - countc[bpos.front()]);
    for (int i = 0; i < count - 1; i++)
    {
        //prefix a bpos[i] and suffix c bpos[i+1]
        ans = min(ans, counta[bpos[i]] + countc[n - 1] - countc[bpos[i + 1]]);
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
