#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n, k;
    cin >> n >> k;
    ordered_set s;
    fr(i, n) s.insert(i + 1);
    int i = k % n;
    while (n--)
    {
        auto x = s.find_by_order(i);
        cout << *x << " ";
        s.erase(x);
        if (n)
            i = (i % n + k) % n;
    }
}
