// Link - https://practice.geeksforgeeks.org/contest/gfg-weekly-178-rated-contest/problems
class Node {
  public:
    vector<int> bits;

    Node() { bits.assign(30, 0); }
};

class STLazy {
  public:
    vector<Node> st;
    vector<int> lazy;
    int M = 1e9 + 7;
    int N;

    STLazy(int n) {
        N = n;
        st.resize(4 * n + 1, Node());
        lazy.resize(4 * n + 1, 0);
    }

    void pull(int idx) {
        for (int bit = 0; bit < 30; bit++) {
            st[idx].bits[bit] = st[2 * idx + 1].bits[bit] + st[2 * idx + 2].bits[bit];
        }
    }

    void propogate(int idx, int low, int high, int val) {
        for (int bit = 0; bit < 30; bit++) {
            if ((1 << bit) & val) {
                st[idx].bits[bit] = (high - low + 1) - st[idx].bits[bit];
            }
        }

        if (low != high) {
            lazy[2 * idx + 1] ^= val;
            lazy[2 * idx + 2] ^= val;
        }
    }

    void build(vector<int> &arr, int idx, int low, int high) {
        if (low == high) {
            for (int bit = 0; bit < 30; bit++) {
                if ((1 << bit) & arr[low]) {
                    st[idx].bits[bit]++;
                }
            }
            return;
        }

        int mid = (low + high) >> 1;
        build(arr, 2 * idx + 1, low, mid);
        build(arr, 2 * idx + 2, mid + 1, high);

        pull(idx);
    }

    void build(vector<int> &arr) {
        build(arr, 0, 0, N - 1);
        return;
    }

    void update(int l, int r, int val, int idx, int low, int high) {
        if (lazy[idx] != 0) {
            propogate(idx, low, high, lazy[idx]);
            lazy[idx] = 0;
        }

        if (l > high || low > r) {
            return;
        }

        if (low >= l and r >= high) {
            propogate(idx, low, high, val);
            return;
        }

        int mid = (low + high) >> 1;
        update(l, r, val, 2 * idx + 1, low, mid);
        update(l, r, val, 2 * idx + 2, mid + 1, high);

        pull(idx);
    }

    void update(int l, int r, int val) {
        update(l, r, val, 0, 0, N - 1);
        return;
    }

    long long query(int l, int r, int idx, int low, int high) {
        if (lazy[idx] != 0) {
            propogate(idx, low, high, lazy[idx]);
            lazy[idx] = 0;
        }

        if (l > high || low > r) {
            return 0LL;
        }

        if (low >= l and r >= high) {
            long long curr = 0;
            for (int bit = 0; bit < 30; bit++) {
                curr += (1LL * st[idx].bits[bit] * (1 << bit));
                curr %= M;
            }
            return curr;
        }

        int mid = (low + high) >> 1;
        return (query(l, r, 2 * idx + 1, low, mid) +
                query(l, r, 2 * idx + 2, mid + 1, high)) %
               M;
    }

    long long query(int l, int r) { return query(l, r, 0, 0, N - 1); }
};

class Solution {
  public:
    vector<int> bitwiseQueries(int N, vector<int> &A, int Q,
                               vector<vector<int>> &queries) {
        STLazy segtree(N);
        segtree.build(A);

        vector<int> ans;
        for (int i = 0; i < Q; i++) {
            int t = queries[i][0], l = queries[i][1], r = queries[i][2],
                x = queries[i][3];

            if (t == 1) {
                segtree.update(l, r, x);
            } else {
                ans.push_back(segtree.query(l, r));
            }
        }

        return ans;
    }
};
