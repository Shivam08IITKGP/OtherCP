#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
// #define v vector
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> demand(n + 1), supply(n + 1);
    vector<ll>subTree_demand(n+1),subTree_supply(n+1);
    vector<int> adj[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> demand[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> supply[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    function<ll(int, int)> dfs = [&](int node, int parent)
    {
        subTree_supply[node] = supply[node];
        subTree_demand[node] = demand[node];
        ll ans = 0;
        for (auto child : adj[node])
        {
            if (child == parent)
                continue;
            // cout<<child<<" "<<node<<"\n";
            ans += dfs(child, node);
            subTree_supply[node] += subTree_supply[child];
            subTree_demand[node] += subTree_demand[child];
        }
        // cout<<"Node = "<<node<<endl;
        // cout<<"Supply = "<<subTree_supply[node]<<endl;
        // cout<<"Demand = "<<subTree_demand[node]<<endl;
        
        // cout<<abs(subTree_demand[node] - subTree_supply[node])<<"\n";
        return ans + abs(subTree_demand[node] - subTree_supply[node]);
    };
    cout << dfs(1, 0) << "\n";
    // cout<<subTree_demand[1]<<" "<<subTree_supply[1]<<"\n";
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
