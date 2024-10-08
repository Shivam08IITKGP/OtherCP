void solve()
{
    int n, k;
    cin >> n >> k;
    vi prime(k);
    read(prime);

    /*

    Then as we get down , you might subtract accordingly as per the odd even parity
    But how to know which indexes are currectly with me, right, the position of bits will tell me

    */

    // vi cnt((1LL << k, 0));
    int ans = 0;
    for (int i = 1; i < (1LL << k); i++)
    {
        // Calculate the lcm of the prime numbers, and store the counts in the cnt[i]
        int lcm = 1;
        int count_bits = 0;
        for (int j = 0; j < k; j++)
        {
            if ((i >> j) & 1)
            {
                count_bits++;
              // checking if the product of the primes is not exceeding n, if it does, then if we set the product to n+1 , then there will be no such multiple of the 
              // product, (0 contribution), hence to not overflow 10^18, we use this technique
                if (lcm > n / prime[j])
                {
                    lcm = n + 1;
                    break;
                }
                lcm *= prime[j];
            }
        }
        // cout << i << " " << lcm << " " << n / lcm << endl;
        if (count_bits & 1)
        {
            ans += n / lcm;
        }
        else
        {
            ans -= n / lcm;
        }
    }
    cout << ans << endl;
}
