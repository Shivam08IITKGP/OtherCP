void solve()
{
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 1, j; i <= n; i = j)
    {
        int q = n / i;
        j = n / q + 1;
        int f = (((j % N) * ((j - 1) % N) % N) * binpow(2, N - 2, N)) % N;
        int s = (((i % N) * ((i - 1) % N) % N) * binpow(2, N - 2, N)) % N;
        ans += (q % N) * (f - s + N) % N;
        ans %= N;
    }
    cout << ans;
}

// Link - https://www.youtube.com/watch?v=JqWiWJQOQyU
