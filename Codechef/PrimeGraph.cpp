// https://www.codechef.com/problems/PRMPRT?tab=statement
void solve()
{
    int n;
    cin >> n;

    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        read(x, y);
        if (x == y)
        {
            cout << 0 << endl;
            continue;
        }
        if (x > y)
        {
            swap(x, y);
        }
        if (spf[x] == x and y % x == 0)
        {
            cout << 1 << endl;
            continue;
        }
        if (__gcd(x, y) > 1)
        {
            cout << 2 << endl;
            continue;
        }
        if (spf[x] * spf[y] <= n)
        {
            cout << 2 + (spf[x] != x) + (spf[y] != y) << endl;
            continue;
        }
        if (spf[x] * 2 <= n and spf[y] * 2 <= n)
        {
            cout << 2 + 2 + (spf[x] != x) + (spf[y] != y) << endl;
            continue;
        }
        else
        {
            cout << -1 << endl;
            continue;
        }
    }
}
