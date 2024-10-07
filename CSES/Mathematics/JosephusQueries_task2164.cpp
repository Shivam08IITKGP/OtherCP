void solve()
{
    int n, k;
    cin >> n >> k;

    function<int(int, int)> calc = [&](int total, int kthChild) -> int
    {
        if (total == 1)
        {
            return 1;
        }
        if (kthChild <= ((total + 1) / 2))
        {
            if (2 * kthChild > total)
            {
                return (2 * kthChild) % total;
            }
            else
            {
                return 2 * kthChild;
            }
        }
        int temp = calc(total / 2, kthChild - (total + 1) / 2);
        if (total % 2 == 1)
        {
            return 2 * temp + 1;
        }
        return 2 * temp - 1;
    };

    cout << calc(n, k) << endl;
}
