void solve()
{
    int n;
    cin >> n;
    vi a(n);
    read(a);
    int x = 0;
    fr(i, n - 1)
    {
        if (a[i + 1] % 2 == 0)
            x ^= (i + 1);
            //Actually what is happening is x^ = (i+1)-> a[i+1] times xor
            //So that's why we take xor of only those i+1 which are having
            //odd a[i+1], (even ones will get canceled out)
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
