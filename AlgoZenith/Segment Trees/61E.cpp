#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

struct SegmentTree {
    vector<int> tree;
    int n;

    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
    }

    void update(int node, int l, int r, int pos, int val) {
        if (l == r) {
            tree[node] += val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2 * node, l, mid, pos, val);
        else update(2 * node + 1, mid + 1, r, pos, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr) +
               query(2 * node + 1, mid + 1, r, ql, qr);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), comp;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        comp.push_back(a[i]);
    }

    // Coordinate compression
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    auto get_comp = [&](int x) {
        return lower_bound(comp.begin(), comp.end(), x) - comp.begin();
    };

    int m = comp.size();
    vector<int> left(n), right(n);

    SegmentTree st(m);

    // Count right[j]: number of elements < a[j] on the right
    for (int i = n - 1; i >= 0; --i) {
        int idx = get_comp(a[i]);
        if (idx > 0)
            right[i] = st.query(1, 0, m - 1, 0, idx - 1);
        st.update(1, 0, m - 1, idx, 1);
    }

    // Reset Segment Tree
    st = SegmentTree(m);

    // Count left[j]: number of elements > a[j] on the left
    for (int i = 0; i < n; ++i) {
        int idx = get_comp(a[i]);
        if (idx < m - 1)
            left[i] = st.query(1, 0, m - 1, idx + 1, m - 1);
        st.update(1, 0, m - 1, idx, 1);
    }

    // Final answer
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += 1LL * left[i] * right[i];
    }

    cout << ans << '\n';
}
