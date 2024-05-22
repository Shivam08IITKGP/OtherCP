#include <bits/stdc++.h>
using namespace std;
// explanation= https://usaco.guide/gold/all-roots

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;

vector<int>adj[200005];
vector<int> first(200005,0),second(200005,0), ans(200005,0);

void dfs1(int node= 1,int parent= 0)
{
    for(auto child:adj[node])
    {
        if(child==parent)
        {
            continue;
        }
        dfs1(child,node);
        if(first[child]+1>first[node])
        {
            second[node]=first[node];
            first[node]=first[child]+1;
        }
        else if( second[node]<first[child]+1)
        {
            second[node]=first[child]+1;
        }
    }
}

void dfs2(int node=1,int parent = 0, int to_parent=0)
{
    ans[node]=max(first[node], to_parent);
    for(auto child: adj[node])
    {
        if(child==parent)
        {
            continue;
        }
        if(first[node]==1+first[child])
        {
            // the largest distance node for the node is on the same path as that of child
            dfs2(child,node, max(second[node],to_parent )+1);
        }
        else if(first[node]>1+first[child])
        {
            // The largest distance node for the node is on some another path as that of child
            dfs2(child,node,ans[node]+1);
        }
    }

}

void solve()
{
    int n;
    cin>>n;
    f(i,0,n-1)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1();
    dfs2();

    f(i,1,n+1)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
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
