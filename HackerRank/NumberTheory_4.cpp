/*
Link =
https://www.hackerrank.com/contests/goc-cdc-series-4/challenges/just-a-simple-sum-3/editorial
*/
void solve()
{
    int n;
    cin >> n;

    int cnt = 0;
    int ans = 1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            ans *= (2 * cnt + 1);
        }
    }
    if (n > 1)
    {
        ans *= 3;
    }

    cout << ans << endl;
}

