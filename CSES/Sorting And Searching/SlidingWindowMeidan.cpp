#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;


int main() {
  int n, k, t;
	cin >> n >> k;
  vector<int>a(n);
	ordered_set s;
	for (int i = 0; i < n; i++) {
		int u;
		cin >> u;
		a[i] = u;
		s.insert({u, t++});
    // First element is element and the second element is index, this is done because 
    // s.erase(s.lower_bound(a[i-k]) removes all occurences of a[i-k] from the set
		if (i >= k) { s.erase(s.lower_bound({a[i - k], 0})); }
		if (i >= k - 1) { cout << (*s.find_by_order((k - 1) / 2)).first << endl; }
	}
}
