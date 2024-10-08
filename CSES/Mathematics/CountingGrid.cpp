void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 2;
        return;
    }
    int ans = 0;
    int n0 = n * n;
    int n90 = 1, n180 = 1;
    if (n & 1)
    {
        n90 = (n * n + 3) / 4;  // Ceiling n*n
        n180 = (n * n + 1) / 2; // Ceiling n*n
    }
    else
    {
        n90 = n * n / 4;
        n180 = n * n / 2;
    }
    ans = (ans + binpow(2, n0, N)) % N;
    ans = (ans + binpow(2, n90, N)) % N;
    ans = (ans + binpow(2, n180, N)) % N;
    ans = (ans + binpow(2, n90, N)) % N;

    cout << (ans * binpow(4, N - 2, N)) % N << endl;
}
