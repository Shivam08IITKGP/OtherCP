void solve()
{
    int n;
    cin>>n;
    graph g(n+1);
    vi subtree(n+1);
    vii edges(n-1);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
        edges[i] = {u,v};
    }
    function<void(int,int)>dfs=[&](int node, int par)->void
    {
        subtree[node]=1;
        for(auto child: g[node])
        {
            if(child!=par)
            {
                dfs(child, node);
                subtree[node]+=subtree[child];
            }
        }
        
    };

    dfs(1, -1);

    int tot = n*(n-1)/2;
    tot = binpow(tot, N-2 , N);

    for(int i=0;i<n-1;i++)
    {
        int u = edges[i].F;
        int v = edges[i].S;
        if(subtree[u]>subtree[v]) swap(u, v);
        int path_through_edge = 1LL*(subtree[u])*(n-subtree[u]);
        int result = (path_through_edge * tot)%N;
        cout<<result<<endl;
    }


}
