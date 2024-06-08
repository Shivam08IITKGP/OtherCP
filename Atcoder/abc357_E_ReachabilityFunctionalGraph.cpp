class Solution
{
public:
    vector<vector<int>> g;
    vector<int> cnt;
    vector<int> indeg;
    vector<int> vis;
    vector<int> v;

    int dfs(int node)
    {
        vis[node] = 1;
        v.push_back(node);

        for (auto ch : g[node])
        {
            if (!vis[ch])
            {
                return 1 + dfs(ch);
            }
        }
        return 1;
    }

    int dfs2(int node)
    {
        vis[node] = 1;

        for (auto ch : g[node])
        {
            if (!vis[ch])
            {
                cnt[node] = 1 + dfs2(ch);
            }
            else if (cnt[ch] != 0 and vis[ch])
            {
                cnt[node] = 1 + cnt[ch];
            }
        }
        return cnt[node];
    }
    vector<int> countVisitedNodes(vector<int> &edges)
    {
        int n = edges.size();
        n--;
        indeg.assign(n+1, 0);
        vis.assign(n+1, 0);
        cnt.assign(n+1, 1);
        // Every node is paired with itself
        g.resize(n+1);
        for (int i = 1; i <= n; i++)
        {
            int a = i;
            int b = edges[i];
            g[a].push_back(b);
            indeg[b]++;
        }
        queue<int> q;

        for (int i = 1; i <= n; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            for (auto i : g[f])
            {
                if (--indeg[i] == 0)
                    q.push(i);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (indeg[i] != 0 and !vis[i])
            {
                v.clear();
                int ans = dfs(i);
                for (auto node : v)
                {
                    cnt[node] = ans;
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                dfs2(i);
            }
        }
        return cnt;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> edges(n+1);
        for (int i = 1; i <= n; i++)
        {
            cin >> edges[i];
        }
        Solution s;
        vector<int> ans = s.countVisitedNodes(edges);
        cout << accumulate(1+all(ans), 0LL) << endl;
    }
}
