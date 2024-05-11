#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define pb push_back
#define f(i, start, end) for (int i = start; i < end; i++)
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long int ll;

vector<vector<ll>> adj;
vector<ll> value;
vector<ll> visited;
multiset<ll> mn, mx;
void adjust_size()
{
    if (mn.size() > mx.size() + 1)
    {
        int temp = *mn.rbegin();
        auto it = mn.end();
        it--;
        mn.erase(it);
        mx.insert(temp);
    }
    else if (mx.size() > mn.size())
    {
        int temp = *mx.begin();
        mx.erase(mx.begin());
        mn.insert(temp);
    }
}
ll ans = 0;

void dfs(ll node, ll size)
{
    visited[node] = 1;
    // current.insert(value[node]);
    if (mn.size() and value[node] > *mn.rbegin())
    {
        mx.insert(value[node]);
    }
    else
    {
        mn.insert(value[node]);
    }
    adjust_size();

    // Check if the size is odd, and if yes, add median to the answer
    if (size&1)
    {
        ans += *mn.rbegin();
        // cout<<ans<<endl;
    }

    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            dfs(child, size + 1);
        }
    }

    // Backtrack
    if (mn.count(value[node]))
    {
        mn.erase(mn.find(value[node]));
    }
    else
    {
        mx.erase(mx.find(value[node]));
    }
    adjust_size();
}

void solve()
{
    ll n;
    cin >> n;
    ans = 0;
    adj.assign(n + 1, vector<ll>());
    value.assign(n + 1, 0);
    visited.assign(n + 1, 0);
    // current.clear();
    mn.clear();
    mx.clear();

    f(i, 1, n + 1)
    {
        cin >> value[i];
    }

    f(i, 0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 1);
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
    return 0;
}
