/*
One important observation to make is that if we can reach the some stone in k moves we can always reach some stone before that in <= k moves.
(Since We can always jump less!). Now while we move towards current maximum stone (call it currmax) we try to 
calculate the maximum stone that can be reached from some stone on the way. We have to make a new move to reach 
this new maximum.(Lets call it newmax). Combining we have :- dp newmax= dp currmax + 1

This way we can calculate for each stone where number of moves changes.

At the end we take suffix minimum to find out the answer for remaining number of floors.
*/

//Link - https://www.hackerrank.com/contests/goc-cdc-series-1/challenges/frog-in-the-pond
//Solution Link - https://www.hackerrank.com/contests/goc-cdc-series-1/challenges/frog-in-the-pond/editorial
#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
using namespace std;
const int MAXN = 100001;
int main()
{       
    
    int n;
    cin>>n;
    int a[2*MAXN],dp[2*MAXN];
    for(int i = 1;i<2*MAXN;i++) dp[i] = MAXN;  
    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    int cnt=2,stone=a[1]+1;  // start from the currmax value
    dp[1] = 0;
    dp[stone] = 1;
    while(stone<n)
    {
        int stone_max_prev=stone;
        while(cnt<=stone_max_prev && stone<=n)
        {
            stone=max(stone,cnt+a[cnt]);
            cnt++;
        }   // stone stores our new_max
        dp[stone] = dp[stone_max_prev] + 1;   // update new_max dp
    }
    // for(int i=0;i<100;i++)
    // {
    //     cout<<dp[i]<<" ";
    // }
    cout<<endl;

    for(int i = 2*MAXN - 2;i>=1;i--){
        dp[i] = min(dp[i],dp[i+1]);          // take suffix mins for values that are not calculated
    }
    int q;
    cin>>q;

    while(q--)
    {
        int k;
        cin>>k;
        cout<<dp[k]<<"\n";
    }

    return 0;
}
