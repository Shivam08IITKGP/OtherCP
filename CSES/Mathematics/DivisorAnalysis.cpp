void solve()
{
    int n;
    cin >> n;
    map<int, int> prime;

    while (n--)
    {
        int x, k;
        cin >> x >> k;
        prime[x] = k;
    }

    int total_factors = 1;
    int total_sum = 1;
    bool flag = 0;
    int pos_odd_exp = -1;

    for (auto it : prime)
    {
        total_factors = (1LL * total_factors * (it.second + 1)) % N;

        int numerator = (binpow(it.first, it.second + 1, N) - 1 + N) % N;
        int denominator;
        if (it.first == 1)
            denominator = 1;
        else
            denominator = binpow(it.first - 1, N - 2, N);

        total_sum = (1LL * total_sum * numerator % N * denominator % N) % N;

        if (it.second & 1 and flag == 0)
        {
            flag = 1;
            pos_odd_exp = it.first;
        }
    }

    cout << total_factors << " " << total_sum << " ";
    
    
    int product_of_divisors = 1;
    if (flag)
    {
        // Then the number is a not a square number
        // Product = Number^(total_factors/2);
        int exp = 1;
        for (auto it : prime)
        {
            // Multiplying 2 at the end by binpow(2, N-3, N-1) will not work as 2 and N-1 are not
            // coprime
            // Hence we will select any beech ka divisor and divide it by 2
            if (it.first == pos_odd_exp)
            {
                exp = (exp * ((1 + it.S) / 2)) % (N - 1);
            }
            else
            {
                exp = (exp * (1 + it.S)) % (N - 1);
            }
        }
        for (auto it : prime)
        {
            product_of_divisors = (product_of_divisors * binpow(it.F, (exp * it.S) % (N - 1), N)) % N;
        }
    }
    else
    {
        // Then the number is a square number
        // Product = sqroot^(total_factors);
        int exp = 1;
        for (auto it : prime)
        {
            exp = (exp * (1 + it.S)) % (N - 1);
        }
        for (auto it : prime)
        {
            product_of_divisors = (product_of_divisors * binpow(it.F, (exp * (it.S / 2)) % (N - 1), N)) % N;
        }
    }
    cout << product_of_divisors;
    return;
}
