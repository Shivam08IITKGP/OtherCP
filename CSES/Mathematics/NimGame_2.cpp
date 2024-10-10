void solve()
{
    int n;
    cin >> n;
    vi a(n);
    read(a);
    int xor_ = 0;
    for (int i = 0; i < n; i++)
    {
        a[i] %= 4;
        xor_ ^= a[i];
    }
    if (xor_ != 0)
    {
        cout << "first\n";
    }
    else
    {
        cout << "second\n";
    }
}
