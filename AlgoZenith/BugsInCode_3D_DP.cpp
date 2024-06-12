int dp[2][501][501];
const int mod = 1e9 + 7;

void solve()
{
    int n, m, b;
    cin >> n >> m >> b;
    vi a(n);
    rep(i, 0, n - 1)
    {
        cin >> a[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    // Basically for the first dimension of the dp, we need only two states,
    // At first we needed to do (when we solving the problem first time)
    /*
    dp[x][y][z]= dp[x][y-1][z-a[i]]+ dp[x-1][y][z]
    First term is taking the ith guy and second term is not taking the ith guy

    As 500x500x500 will be MLE, we will take x&1 instead of storing x in the
    1st dimension
    Reason is for odd index(1 to n) we need dp[1][j][k]= dp[0][j][k]
    As dp[0][0][0] = 1


    */
    for (int i = 1; i <= n; i++)
    {
        int p = i % 2;
        // p is 1 for i = odd and 0 for i = even
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= b; k++)
            {
                // For i=  odd, dp[1][j][k]= dp[0][j][k]
                // For i= even, dp[0][j][k]= dp[1][j][k]
                dp[p][j][k] = dp[p ^ 1][j][k];
                if (j and k >= a[i - 1])
                {
                    dp[p][j][k] = (dp[p][j][k] + dp[p][j - 1][k - a[i - 1]]) % mod;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= b; i++)
    {
        ans = (ans + dp[n % 2][m][i]) % mod;
    }
    cout << ans << endl;
}
