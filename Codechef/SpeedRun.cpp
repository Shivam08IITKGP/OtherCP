void solve()
{
    int n, k;
    read(n, k);
    vi a(n), h(n);
    read(a);
    read(h);
    int pre = 0;
    int index = -1;

    rep(i, 0, n - 1)
    {
        if (pre + h[i] > a[i])
        {
            index = i;
            break;
        }
        pre += h[i];
    }
    if (index == -1)
    {
        cy
    }

    int index2 = n - 1;
    rep(i, index, n - 1)
    {
        if (a[i] - a[index] > 2 * k)
        {
            index2 = i - 1;
            break;
        }
    }
    per(i, index2, 0)
    {
        if (a[index2] - a[i] > 2 * k)
        {
            break;
        }
        h[i] = 0;
    }
    pre = 0;
    rep(i, 0, n - 1)
    {
        if (pre + h[i] > a[i])
        {
            cn;
        }
        pre += h[i];
    }
    cy;
}
