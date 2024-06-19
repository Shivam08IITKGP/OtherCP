https://www.hackerrank.com/contests/goc-cdc-series-7/challenges/sets-fusion/editorial
void solve()
{
    int n, m, k1, k2;
    read(n, m, k1, k2);
    set<int> A, B;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        B.insert(x);
    }
    vi a(all(A));
    vi b(all(B));

    n = a.size();
    m = b.size();

    int gcd = 0;
    fr(i, n - 1)
    {
        gcd = __gcd(k1 * (a[i + 1] - a[0]), gcd);
    }
    fr(i, m - 1)
    {
        gcd = __gcd(gcd, k2 * (b[i + 1] - b[0]));
    }
    gcd = __gcd(gcd, a[0] * k1 + b[0] * k2);
    cout << gcd << endl;
}
