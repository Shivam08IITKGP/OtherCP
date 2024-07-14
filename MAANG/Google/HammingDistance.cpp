#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define EB emplace_back
#define sz(v) (int)v.size()
#define int long long
#define MP make_pair
#define all(o) (o).begin(), (o).end()
#define rall(o) (o).rbegin(), (o).rend()
#define mset(m,v) memset(m,v,sizeof(m))
#define fr(i,n) for(int i=0;i<n;++i)
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b))) 
#define pb push_back
#define endl '\n'
#define cy cout<<"YES"<<endl; return;
#define cn cout<<"NO"<<endl; return;

typedef long long ll;        
typedef long double ld;
typedef pair<ll,ll> ii;     
typedef vector<ll> vi;
typedef vector<ii> vii;       
typedef vector<vi> graph;

long double EPS=1e-9;
long long M = 998244353;
const int N= 1e9+7;
const int V = 2e5 + 5;
const int INF = 1e18;

template<class T> void read1(vector<T> &a){ for (int i = 1; i < sz(a); i++) cin>>a[i];}

graph g;
vector<int> vis;
int id = 0;

void dfs(int node) {
    for(auto child: g[node]) {
        if(!vis[child]) {
            vis[child] = id;
            dfs(child);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    id = 0;
    g.assign(n + 1, vi(0));
    vis.assign(n + 1, 0);
    vi a(n+1), b(n+1);
    read1(a);
    read1(b);
    
    
    fr(i, m) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            vis[i] = ++id;
            dfs(i);
        }
    }

    int ans = 0;
    vector<vi> comp(id + 1);
    for(int i = 1; i <= n; i++) {
        comp[vis[i]].pb(i);
    }

    for(int i = 1; i <= id; i++) {
        map<int, int> m;
        for(int j = 0; j < sz(comp[i]); j++) {
            m[a[comp[i][j]]]++;
        }

        for(int j = 0; j < sz(comp[i]); j++) {
            if(m[b[comp[i][j]]]) {
                m[b[comp[i][j]]]--;
            } else {
                ans++;
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
