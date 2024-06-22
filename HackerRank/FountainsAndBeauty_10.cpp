#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,c,d ;
    cin>>n>>c>>d ;
    int b[n],p[n],t[n] ;
    for(int i=0;i<n;i++)
        cin>>b[i]>>p[i]>>t[i] ;
    vector<pair<int,int>>type_0,type_1 ;
    for(int i=0;i<n;i++)
    {
        if(t[i]==0)
        {
            type_0.push_back({p[i],b[i]}) ;
        }
        else
        {
            type_1.push_back({p[i],b[i]}) ;
        }
    }
    sort(type_0.begin(),type_0.end()) ;
    sort(type_1.begin(),type_1.end()) ;
    // One using coins and one using diamonds 
    int max_0=0,max_1=0 ;
    int x=type_0.size() ;
    int y=type_1.size() ;
    for(int i=0;i<x;i++)
    {
        if(type_0[i].first<=c)
            max_0=max(max_0,type_0[i].second) ;
    }
    for(int i=0;i<y;i++)
    {
        if(type_1[i].first<=d)
            max_1=max(max_1,type_1[i].second) ;
    }
    int ans=0 ;
    if(max_0&&max_1)
        ans=max(ans,max_0+max_1) ;   
    // Both using coins
    multiset<int>m;                         
    for(int i=0;i<x;i++)
    {
       m.insert(type_0[i].second) ;
    }
    int j=type_0.size()-1 ;
    for(int i=0;i<x;i++)
    {
        if(j<=i)
            break ;
        auto it=m.find(type_0[i].second) ;
        m.erase(it) ;
        int flag=0 ;    
        while(j>i)
        {
            if(type_0[j].first+type_0[i].first<=c)
            {
                flag=1 ;
                break ;
            }
            auto it=m.find(type_0[j].second) ;
            m.erase(it) ;
            j-- ;
        }
        if(flag==0)
            break ;
        if(m.size())
        ans=max(ans,type_0[i].second+*m.rbegin()) ;   
    }
    // Both using diamonds
    m.clear() ;
    for(int i=0;i<y;i++)
    {
       m.insert(type_1[i].second) ;
    }
     j=type_1.size()-1 ;
    for(int i=0;i<y;i++)
    {
        if(j<=i)
            break ;
        auto it=m.find(type_1[i].second) ;
        m.erase(it) ;
        int flag=0 ;
        while(j>i)
        {
            if(type_1[j].first+type_1[i].first<=d)
            {
                flag=1 ;
                break ;
            }
            auto it=m.find(type_1[j].second) ;
            m.erase(it) ;
            j-- ;
        }
        if(flag==0)
            break ;
        if(m.size())
        ans=max(ans,type_1[i].second+*m.rbegin()) ;
    }
    cout<<ans<<"\n" ;
    return 0;
}
