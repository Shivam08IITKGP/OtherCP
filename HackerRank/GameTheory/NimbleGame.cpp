void solve()
{
    int n;
    cin >> n;
    vi a(n);
    read(a);
    int x = 0;
    fr(i, n)
    {
        if (a[i] % 2 != 0)
            x ^= (i);
        // Actually what is happening is x^ = (i)-> a[i] times xor
        // So that's why we take xor of only those i+1 which are having
        // odd a[i], (even ones will get canceled out)
    }
    if (x > 0)
    {
        cout << "First\n";
    }
    else
    {
        cout << "Second\n";
    }
}
