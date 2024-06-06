void solve()
{
    int n, a, b;
    read(n, a, b);
    if (a == b)
    {
        cout << n / a << endl;
        return;
    }
    a = min(a, b);
    int div = n / a;
    if (n >= a * (a - 1))
    {
        cout << n - a * (a - 1) / 2 << endl;
        return;
    }
    int ans = div * a - div * (div + 1) / 2;
    int rem = n % a;
    ans += max(0LL, rem - div);
    cout << n - ans << endl;
}
