void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int x = binpow(b, c, N - 1);
    cout << binpow(a, x, N) << endl;
}
