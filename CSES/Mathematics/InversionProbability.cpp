void solve()
{
    int n;
    cin >> n;
    vi r(n);
    read(r);

    // Now we have an array x1, x2, ...., xn where each xi is between 1 to ri
    // WE have to find the expected number of inversions in the x array
    ld ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int k;
            if (r[j] <= r[i])
            {
                k = r[j] * (r[j] - 1) / 2 + (r[i] - r[j]) * r[j];
                // rjC2 is for taking two elements from r[j] range only
                // The other term is for xi to be in range r[i] to r[j]
                // and xj to be in range 1 to r[j]
            }
            else // Take two numbers from r[i], give the greater one to xi and smaller one to xj
            {
                k = r[i] * (r[i] - 1) / 2;
            }
          // Why divide by their product, still unclear, but learn
            ans += (ld)(k) / (ld)(r[i] * r[j]);
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
}
