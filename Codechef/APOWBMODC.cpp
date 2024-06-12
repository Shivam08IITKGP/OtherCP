#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    long long int a;
	    cin>>a;
	    if(a==2)
	    {
	        cout<<4<<" "<<8<<endl;
	        continue;
	    }
	    cout<<2*a<<" "<<a*a<<endl;
	}

}
