#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define v vector
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;

void solve()
{
    int n;
    cin>>n;

    vector<int>dist(n+1,INT_MAX);
    deque<int>q;
    q.push_back(1);
    dist[1]=1;
    while(!q.empty())
    {
        int u=q.back();
        q.pop_back();

        int case1= (u*10)%n;
        int case2= (u+1)%n;

        if(dist[case1]>dist[u])
        {
            dist[case1]=dist[u];
            q.push_back(case1);
        }
        if(dist[case2]>dist[u]+1)
        {
            dist[case2]=dist[u]+1;
            q.push_front(case2);
        }

    }
    cout<<dist[0]<<endl;
}

int main()
{
    FAST;
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
