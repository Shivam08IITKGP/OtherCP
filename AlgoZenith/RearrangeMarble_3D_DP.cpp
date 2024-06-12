int dp[101][101][2];
int k1, k2;
const int mod = 1e8;
int mem(int n1, int n2, int f)
{
    if (n1 + n2 == 0)
    {
        return 1;
    }
    if (dp[n1][n2][f] != -1)
    {
        return dp[n1][n2][f];
    }
    dp[n1][n2][f] = 0;

    if (f == 0)
    {
        for (int i = 1; i <= min(n1, k1); i++)
        {
            dp[n1][n2][f] = (dp[n1][n2][f] + mem(n1 - i, n2, 1 - f)) % mod;
        }
    }
    else
    {
        for (int i = 1; i <= min(n2, k2); i++)
        {
            dp[n1][n2][f] = (dp[n1][n2][f] + mem(n1, n2 - i, 1 - f)) % mod;
        }
    }
    return dp[n1][n2][f];
}

void solve()
{
    int n1, n2;
    read(n1, n2, k1, k2);
    memset(dp, -1, sizeof(dp));
    int firstElem_1 = mem(n1, n2, 0);
    int firstElem_2 = mem(n1, n2, 1);
    cout << (firstElem_1 + firstElem_2) % mod << endl;
}
