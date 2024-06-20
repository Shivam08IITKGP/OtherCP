/*

We have given an adjacency representation of a directed
weighted graph and an array of vertices. At each iteration,
a vertex is removed from the graph. Vertices are removed 
in the order given in the array. When the vertex is removed, 
all the edges that go in and out are also removed. 

Print the sum of all pairs shortest path just before each iteration.
*/

/*
In Floyd-Warshall algorithm we do iterations like this:

for all k in (1, n) : D[i][j] = min(D[i][j], D[i][k] + D[k][j]).

When we do this we assume that from vertex i to j we already found
the shortest path which has all intermediate vertices in the set 
{1, 2, …, k-1}. After D[i][j] = min(D[i][j], D[i][k] + D[k][j]), 
we will get the shortest path from i to j which has all intermediate 
vertices in the set {1,2, …, k}.

For solving the problem we will use this concept of Floyd-Warshall 
algorithm. Instead of going forward, we will add vertices from the
backward of the array. So running time of the algorithm is as same
as Floyd Warshall algorithm i.e. O(n3).
*/

#include<bits/stdc++.h>
#define ll long long int
#define N 510
using namespace std;
 
ll inf=1e16;
int main()
{
    int n;
    ll A[N][N];
    scanf("%d",&n);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%lld",&A[i][j]);
    vector<ll> ans;
    int x[N];
    for(int i=0;i<n;i++) scanf("%d",&x[i]),x[i]--;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<n;j++) for(int k=0;k<n;k++) A[j][k]=min(A[j][k],A[j][x[i]]+A[x[i]][k]);
        ll temp=0;
        for(int j=i;j<n;j++) for(int k=i;k<n;k++) temp+=A[x[j]][x[k]];
        ans.push_back(temp);
    }
    for(int i=(int)ans.size()-1;i>=0;i--) printf("%lld ",ans[i]);
    return 0;
}
