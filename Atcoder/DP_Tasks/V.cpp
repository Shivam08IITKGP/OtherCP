const int N = 1e5 + 1;
graph tree(N);
int n, m;
vi leftSubtree[100001], rightSubtree[100001], up(100001), down(100001), ans(100001);

int dfs1(int node, int par)
{
    int s = tree[node].size();
    int arr[s];
    for (int i = 0; i < s; i++)
    {
        if (tree[node][i] == par)
        {
            arr[i] = 1;
            continue;
        }
        arr[i] = (1 + dfs1(tree[node][i], node)) % m;
    }
    leftSubtree[node].resize(s);
    rightSubtree[node].resize(s);
    leftSubtree[node][0] = arr[0];
    rightSubtree[node][s - 1] = arr[s - 1];

    for (int i = 1; i < s; i++)
    {
        leftSubtree[node][i] = (leftSubtree[node][i - 1] * arr[i]) % m;
        rightSubtree[node][s - i - 1] = (rightSubtree[node][s - i] * arr[s - i - 1]) % m;
    }
    return down[node] = rightSubtree[node][0];
}

void dfs2(int node, int par)
{
    int s = tree[node].size();
    for (int i = 0; i < s; i++)
    {
        if (tree[node][i] == par)
        {
            continue;
        }

        // Here we are calculating the product of the depth of the nodes outside the subtree v

        int left = (i != 0) ? leftSubtree[node][i - 1] : 1;
        int right = (i != s - 1) ? rightSubtree[node][i + 1] : 1;

        // Note the +1 
        // Why 
        up[node] = (((((left * right) % m) * up[par]) % m) + 1) % m;

        //Note the below line -> Interesting
        ans[tree[node][i]] = (down[tree[node][i]] * up[node]) % m;
        dfs2(tree[node][i], node);
    }
}

void solve()
{
    read(n, m);
    rep(i, 1, n - 1)
    {
        int u, v;
        read(u, v);
        tree[u].pb(v);
        tree[v].pb(u);
    }
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }

    ans[1] = dfs1(1, 0);
    up[0] = 1;
    dfs2(1, 0);
    rep(i, 1, n)
    {
        cout << ans[i] << endl;
    }
}
