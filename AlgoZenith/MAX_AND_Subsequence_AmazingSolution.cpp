#include <bits/stdc++.h>
using namespace std;

/*
Take all the numbers with highestBit set if the count is >=X. 
Add 1<<(highestBit) in your answer. Now your problem reduces to 
the array of elements with highestBit set and highestBit-1 be the
next bit to be considered. If the subsequence of length X is not present 
then calculate the answer for the same array with highestBit-1 as the new
highestBit possible.
*/

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

   int testCase;
   cin>>testCase;
   while(testCase--){
       int n,x;
       cin>>n>>x;
       vector < int > arr(n);
       for(int i=0;i<n;i++)
           cin>>arr[i];
       int ans = 0;
       for(int i=29;i>=0;i--){
           vector < int > elementBitSet;
           for(auto v:arr){
               if(v&(1LL<<i))
                   elementBitSet.push_back(v);
           }
           if(elementBitSet.size()>=x){
               ans+=(1LL<<i);
               arr = elementBitSet;
           }
       }
       cout<<ans<<"\n";
   }

}
