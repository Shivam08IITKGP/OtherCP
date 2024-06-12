vi segmentTree;
int m;

void build(vi &a, int v, int tl, int tr) {
    if (tl == tr) {
        segmentTree[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2 + 1, tl, tm);
        build(a, v * 2 + 2, tm + 1, tr);
        segmentTree[v] = (segmentTree[v * 2 + 1] * segmentTree[v * 2 + 2]) % m;
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 1;
    if (l == tl && r == tr) {
        return segmentTree[v];
    }
    int tm = (tl + tr) / 2;
    return (query(v * 2 + 1, tl, tm, l, min(r, tm)) * query(v * 2 + 2, tm + 1, tr, max(l, tm + 1), r)) % m;
}

void solve() {
    int n, k;
    cin >> n >> k >> m;
    vi a(n);
    fr(i, n) cin >> a[i];
    fr(i, n) a[i] %= m;
    
    segmentTree.assign(4 * n, 1);
    build(a, 0, 0, n - 1);
    
    vi dp(n, 0);
    dp[0] = a[0];
    for (int i = 1; i < n; i++) {
        int ans = (dp[i - 1] * a[i] + a[i]) % m;
        if (i < k) {
            dp[i] = ans;
            continue;
        }
        int prod = query(0, 0, n - 1, i - k, i) % m;
        ans = (ans - prod + m) % m;
        dp[i] = ans;
    }
    cout << accumulate(all(dp), 0LL) % m << endl;
}
