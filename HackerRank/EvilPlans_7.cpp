// If you start from every node, do BFS, then you will get TLE 
// Do instead Multisource BFS

#include <iostream>
#include<algorithm>
#include<queue>

using namespace std;
#define trace(x) cerr << #x << ": " << x << " " << endl;
#define int long long

void solve(int n, int m, int q, vector<pair<int, int>> ar, int r, vector<vector<bool>> &out)
{
    queue<pair<pair<int,int>, int>> qu;
    for(auto it:ar)
    {
        qu.push({it,0});
        out[it.first][it.second]=1;
    }
    int cnt=0;
    while(!qu.empty())
    {
        cnt++;
        pair<pair<int,int>, int> fr = qu.front();
        qu.pop();
        int x = fr.first.first;
        int y = fr.first.second;
        int dep = fr.second;

        if(dep==r)
        {
            break;
        }
        if(x>0 && !out[x-1][y])
        {
            out[x-1][y]=1;
            qu.push({{x-1,y},dep+1});
        }
        if(x<n-1 && !out[x+1][y])
        {
            out[x+1][y]=1;
            qu.push({{x+1,y},dep+1});
        }
        if(y>0 && !out[x][y-1])
        {
            out[x][y-1]=1;
            qu.push({{x,y-1},dep+1});
        }
        if(y<m-1 && !out[x][y+1])
        {
            out[x][y+1]=1;
            qu.push({{x,y+1},dep+1});
        }
    }
}

int n,m,q,r;
vector<pair<int, int>> ar;
signed main()
{
    int x,y;
    cin>>n>>m>>q>>r;
    vector<vector<bool>> out(n,vector<bool>(m,0));

    for(int i=0;i<q;i++)
    {
        cin>>x>>y;
        ar.push_back({x-1,y-1});
    }

    solve(n,m,q,ar,r,out);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<out[i][j]<<" ";
        }
        cout<<endl;
    }
}
