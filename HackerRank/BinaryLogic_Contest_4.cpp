#include<bits/stdc++.h>
using namespace std;

int main()
{      
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int res = 0;
    for(int i = 0; i < n ; i++){
        res = (res * 2 + (s[i] - '0')) % k;
    }
    if(res == 0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
