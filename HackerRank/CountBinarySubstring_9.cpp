#include<bits/stdc++.h>
using namespace std;

int getSubstringCount(string s){
    //Code
    int n = s.length();
    
    int ans = 0;

    int len1 = 0, len2 = 1;
    for(int i=1;i<n;i++){
        if(s[i] != s[i-1]){
            ans += min(len1,len2);
            len1 = len2;
            len2 = 1;
        }
        else{
            len2++;
        }
    }
    ans += min(len1,len2);

    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout << getSubstringCount(s) << '\n';
    }
}
