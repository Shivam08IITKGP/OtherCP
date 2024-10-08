void solve()
{
    int n;
    cin >> n;
    vi a(n);
    read(a);

    vi a_values_Divisible_By(V, 0);
    vi primeDivisors_count(V, 0);

    // Sieve to get smallest prime factor (SPF) for each number
    vi spf(V); // smallest prime factor
    for (int i = 2; i < V; i++)
        spf[i] = i;
    for (int i = 2; i * i < V; i++)
    {
        if (spf[i] == i) // i is a prime
        {
            for (int j = i * i; j < V; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }

    // Function to factorize a number using SPF
    auto getPrimeFactors = [&](int x) {
        set<int> factors;
        while (x > 1)
        {
            factors.insert(spf[x]);
            x /= spf[x];
        }
        return factors;
    };

    // Count divisors and apply inclusion-exclusion principle
    for (int i = 0; i < n; i++)
    {
        set<int> factors = getPrimeFactors(a[i]);
        vi divisors;
        divisors.push_back(1);
        for (int prime : factors)
        {
            int sz = divisors.size();
            for (int j = 0; j < sz; j++)
            {
                divisors.push_back(divisors[j] * prime);
            }
        }

        for (int d : divisors)
        {
            a_values_Divisible_By[d]++;
        }
    }

    int total_pairs = (n * (n - 1)) / 2;
    int invalid_pairs = 0;

    // Apply inclusion-exclusion
    for (int i = 2; i < V; i++)
    {
        if (a_values_Divisible_By[i] > 1)
        {
            int cnt = a_values_Divisible_By[i];
            int pairs = (cnt * (cnt - 1)) / 2;
            // If i has an odd number of distinct prime factors, we add the pairs, otherwise subtract
            set<int> prime_factors = getPrimeFactors(i);
            if (prime_factors.size() & 1)
                invalid_pairs += pairs;
            else
                invalid_pairs -= pairs;
        }
    }
    cout << total_pairs - invalid_pairs << endl;
}
