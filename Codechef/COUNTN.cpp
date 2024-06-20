vi spf(V, 0);
vi prefixSum(V, 0);
void sieve()
{
    for (int i = 2; i < V; i++)
    {
        spf[i] = i;
    }
    for (int i = 2; i < V; i++)
    {
        if (spf[i] == i)
        {
            for (int j = 2 * i; j < V; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
    for (int i = 2; i < V; i++)
    {
        if (spf[i] == i)
        {
            prefixSum[i] = prefixSum[i - 1] + i;
        }
        else
        {
            prefixSum[i] = prefixSum[i - 1];
        }
    }
}
// Suppose N = d * alpha
// A number N has a spf = alpha, this means that the smallest divisor of N is alpha (except 1)
// Rest of the divisors either can be broken and transfered to the alpha
// We will calculate sum of primes till the spf of d (incl spf of d)
void solve()
{
    int n;
    cin >> n;

    int x = spf[n];
    int z = prefixSum[x];
    cout << n * z << endl;
}
