void multiply(graph &a, graph &b)
{
    graph res(6, vi(6, 0));
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= N;
            }
        }
    }
    a = res;
}

void solve()
{
    int n;
    cin >> n;
    graph x(6, vi(6, 0)), y(6, vi(6, 0));
    for (int i = 0; i < 6; i++)
    {
        x[0][i] = 1;
        y[i][i] = 1;
    }
    for (int i = 0; i < 5; i++)
    {
        x[i + 1][i] = 1;
    }
    /*
    x matrix
    1 1 1 1 1 1 
    1 0 0 0 0 0 
    0 1 0 0 0 0 
    0 0 1 0 0 0 
    0 0 0 1 0 0 
    0 0 0 0 1 0 

    y matrix -> identity matrix
    */


    while (n)
    {
        if (n & 1)
            multiply(y, x);
        multiply(x, x);
        n >>= 1;
    }
    

    cout << y[0][0];
}
