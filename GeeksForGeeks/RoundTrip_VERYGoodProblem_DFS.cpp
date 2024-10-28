void dfs(int u, int p, vector<vector<pair<int,int>>>&edge, vector<long long>&dp, vector<int>&a)
    {
        dp[u] = a[u];
        for(auto neigh: edge[u])
        {
            int v = neigh.first;
            int len = neigh.second;
            
            if(v!=p)
            {
                dfs(v, u, edge, dp, a);
                dp[u]+= max(0LL, dp[v] - 2LL*len);
            }
        }
    }
long long roundTrip(int n, vector<int> &a, vector<vector<int>> &g) 
    {
        // code here
        vector<vector<pair<int,int>>>edge(n);
        for(int i=0;i<n-1;i++)
        {
            int u = g[i][0], v = g[i][1], len = g[i][2];
            u--;
            v--;
            edge[u].push_back({v, len});
            edge[v].push_back({u, len});
        }
        
        vector<long long> dp(n);
        dfs(0, -1, edge, dp, a);
        
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            ans = max(ans, dp[i]);
        }
        return ans;
    }

// Link -> https://practice.geeksforgeeks.org/contest/gfg-weekly-178-rated-contest/problems
