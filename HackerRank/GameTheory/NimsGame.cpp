#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for(auto &x : a) {
            cin >> x;
        }

        int xor_sum = 0;
        for(auto i : a) {
            xor_sum ^= i;
        }

        if(xor_sum != 0) {
            cout << "First\n";
        } else {
            cout << "Second\n";
        }
    }
    
    return 0;
}
