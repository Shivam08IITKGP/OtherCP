
const int N = 1e6 + 1;
vi prime[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 2; i < N; i++)
    {
        if (prime[i].empty())
            for (int j = i; j < N; j += i)
            {
                prime[j].push_back(i);
            }
    }
    while (t--)
    {
        int n;
        cin >> n;

        vi a(n);
        read(a);
        vi dp(n, 0);
        vi mn(N, n + 1);

        dp[0] = 1;

        for (int p : prime[a[0]])
        {
            mn[p] = 0;
        }

        for (int i = 1; i < n; i++)
        {
            dp[i] = 1 + dp[i - 1];
            for (int p : prime[a[i]])
            {
                remin(dp[i], 1 + mn[p]);
                remin(mn[p], dp[i - 1]);
                //Doubt

            }
            // cout<<"mn[2] = "<<mn[2]<<" mn[3] = "<<mn[3]<<endl;
        }
        cout << dp[n - 1] << endl;
    }
}
