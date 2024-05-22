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
    ll n;
    cin >> n;
    vector<int> a(n + 1);
    f(i, 0, n)
    {
        cin >> a[i];
    }
    int lastVisited = 0;
    
    ll sum = 0;
    f(i, 1, n)
    {
        if (a[i] <= a[lastVisited])
        {
            sum += (i - lastVisited) * (a[lastVisited]);
            lastVisited = i;
        }
    }

    if(lastVisited!=n-1)
    {
        int previous= n-1;
        fr(i,n-2,lastVisited-1)
        {
            if(a[i]<=a[previous])
            {
                sum += (previous-i)*(a[previous]);
                previous = i;
            }
        }
        if(previous!=lastVisited)
        {
            sum += (previous-lastVisited)*(max(a[previous],a[lastVisited]));        
        }
    }
    cout << sum << endl;
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
/*
1.Since the cost of path is max(Ai,Aj)*abs(j-i), we can easily observe that going from i->j is optimal only and only if Aj<=Ai.

2.We cannot go back. i.e, we must not move from j->i such that j>i.
(Proof1 : suppose you go from I->j where Aj<=Ai. now we go to i->k->j such that Ak>Ai. so the total cost will be Ak*(k-i) + Ak*(j-k) = Ak*(j-i), which is greater than Ai*(j-i).)

(Proof2: Trivial)

Now the question arises: which j should we choose? In this case, choosing j greedily works out, the proof of which is underlined below:

Suppose we have j1 and j2 such that Ij2 and I->j1->j2 and examine which is shorter.

cost1 : A[i](j2-i) cost2 : A[i](j1-i) + A[j]*(j2-j1). Since A[j]<=A[i], we can express A[j] as A[i]-x where x>=0;

clearly cost2 can be expressed as: A[i](j2-i)-x(j2-j1) <= cost1

Hence we must always choose the path greedily and choose each j such that A[j]<=A[prev] where prev is the previously chosen index, starting with 1.

Now there arise 2 cases:

A[n]<=A[1]
A[n] > A[1]
In the former case, our approach trivially solves the problem. However in the second case, we can see it as solving the problem after reversing the array. I.e, start from n and move to the last visited element.

So we apply the above mentioned approach now but starting with A[n] and moving to the last visited element, and choosing the first I such that A[i]<=A[n], and finally reach the last visited element from the back.
*/
