#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    sort(begin(v),end(v));
    int ans=0;
    int maxend=0;
    for(int i=0;i<n;i++)
    {
        ans+= max(v[i].second,maxend)-max(v[i].first-1,maxend);
        maxend=max(maxend,v[i].second);
    }
    cout<<ans<<endl;
}





int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    solve();
    return 0;
}
