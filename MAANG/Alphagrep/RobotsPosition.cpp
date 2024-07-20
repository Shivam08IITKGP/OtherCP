/*
result[endR] += (totalR + 1) / 2;: Robots on 'R' segment:
Robots in the 'R' segment are evenly distributed, but since there can be an odd number of robots, we add (totalR + 1) / 2 
to the position endR to handle the majority of 'R's converging at the rightmost 'R' position.
result[endR + 1] += totalR / 2;: The remaining robots from the 'R' segment:
The rest of the robots from 'R' segment (which is totalR / 2) will move one step to the right, hence they go to endR + 1.
result[endR] += totalL / 2;: Robots on 'L' segment:
Similarly, robots in the 'L' segment are also distributed. Here, totalL / 2 robots from the 'L' segment will be added to 
the rightmost 'R' position.
result[endR + 1] += (totalL + 1) / 2;: The remaining robots from the 'L' segment:
The rest of the robots from 'L' segment (which is (totalL + 1) / 2) will move one step to the left, hence they go to
endR + 1.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> result(n, 0);

    for (int i = 0; i < n; ) {
        if (s[i] == 'R') {
            int start = i;
            while (i < n && s[i] == 'R') ++i;
            int endR = i - 1;
            while (i < n && s[i] == 'L') ++i;
            int endL = i - 1;

            int totalR = endR - start + 1;
            int totalL = endL - endR;
            
            // Distribute robots to the end positions
            result[endR] += (totalR + 1) / 2;
            result[endR + 1] += totalR / 2;
            result[endR] += totalL / 2;
            result[endR + 1] += (totalL + 1) / 2;
        } else {
            ++i;  // move to the next 'R'
        }
    }
    
    for (int x : result) {
        cout << x;
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
