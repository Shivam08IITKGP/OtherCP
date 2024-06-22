int ceel(int a, int b)
{
    return (a + b - 1) / b;
}
void solve()
{
    int a, b, x, y;
    read(a, b, x, y);
    int ans = 0;

    if (x == y)
    {
        if (a != b)
        {
            cout << -1 << endl;
            return;
        }
    }
    else if (x == 0)
    {
        if (a != 0)
        {
            cout << -1 << endl;
            return;
        }
    }
    else
    {
        ans = y * max(ceel(a, x), max(ceel(b, y), ceel(b - a, y - x))) - b;
        cout << ans << endl;
        return;
    }
    cout << 0 << endl;
    return;
}
