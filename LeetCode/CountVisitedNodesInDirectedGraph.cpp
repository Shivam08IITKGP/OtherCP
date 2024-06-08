class Solution {
public:

  
    vector<vector<int>> g;
    vector<int> cnt;
    vector<int> indeg;
    vector<int> vis;
    vector<int> v;
    // For cyclic nodes
    int dfs(int node)
    {
        vis[node]=1;
        v.push_back(node);

        for(auto ch: g[node])
        {
            if(!vis[ch])
            {
                return 1+dfs(ch);
            }
        }
        return 1;
    }

    // For Non Cyclic nodes
    int dfs2(int node)
    {
        vis[node]=1;
        
        for(auto ch:g[node])
        {
            if(!vis[ch])
            {                
                cnt[node]= 1+dfs2(ch);
            }
            else if(cnt[ch]!=0 and vis[ch])
            {
                cnt[node]= 1+cnt[ch];
            }          
        }
        return cnt[node];
    }
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        indeg.assign(n,0);
        vis.assign(n,0);
        cnt.assign(n,1);
        //Every node is paired with itself
        g.resize(n);
        for (int i = 0; i < n; i++) {
            int a = i;
            int b = edges[i];
            g[a].push_back(b);
            indeg[b]++;
        }
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }


        while (!q.empty()) {
            int f = q.front();
            q.pop();
            for(auto i: g[f])
            {
                if(--indeg[i]==0) q.push(i);
            }
        }
        //For cyclic nodes -> count will be the cycle length
        for(int i=0;i<n;i++)
        {
            if(indeg[i]!=0 and !vis[i])
            {
                v.clear();
                int ans= dfs(i);
                for(auto node: v)
                {
                    cnt[node]= ans;
                }
            }
        }

      //For non cyclic nodes -> Depth of the node in the tree + Cycle Length
        for(int i=0;i<n;i++){
            if(!vis[i])
            {
                dfs2(i);
            }
        }
        return cnt;
    }
};
