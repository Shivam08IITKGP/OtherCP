https://practice.geeksforgeeks.org/contest/gfg-weekly-156-rated-contest/problems

/*
We can use a depth-first search (DFS) approach to explore the tree structure of Geekland.
For each city, we keep track of the number of consecutive haunted cities visited so far. 
If this count exceeds m, we stop exploring further from that city. Otherwise, we continue
DFS traversal, updating the count and considering whether the current city is a leaf city.
*/
class Solution {
  public:
    void dfs(int curr_node, int par_node, int m, int haunted_visited, int *ans,
             vector<int> &isHaunted, vector<int> adj[]) {
        if (haunted_visited > m)
            return;
        int ok = 1;
        for (int i = 0; i < adj[curr_node].size(); i++) {
            if (adj[curr_node][i] != par_node) {
                ok = 0;
                dfs(adj[curr_node][i], curr_node, m,
                    haunted_visited * isHaunted[adj[curr_node][i]] +
                        isHaunted[adj[curr_node][i]],
                    ans, isHaunted, adj);
            }
        }
        *ans = (*ans + ok);
    }

    int citiesVisited(int n, int m, vector<int> &isHaunted,
                      vector<vector<int>> &edges) {
        vector<int> adj[n];
        for (int i = 0; i < n - 1; i++) {
            adj[edges[i][0] - 1].push_back(edges[i][1] - 1);
            adj[edges[i][1] - 1].push_back(edges[i][0] - 1);
        }
        int ans = 0;
        dfs(0, -1, m, isHaunted[0], &ans, isHaunted, adj);
        return ans;
    }
};
