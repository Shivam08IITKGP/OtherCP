const int MOD = 1e9 + 7;
vector<vector<int>> comb;
vector<int> dp;

void calculateCombinations(int A) 
{
    comb.resize(A + 1, vector<int>(A + 1, 0));
    for (int i = 0; i <= A; ++i) 
    {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; ++j) 
        {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }
}

int getLeftSubtreeSize(int A) 
{
    if (A == 1) return 0;

    int h = (int)log2(A);
    int maxNodesAtHeight = (1 << h); // 2^h
    int lastLevelNodes = A - ((1 << h) - 1);

    if (lastLevelNodes >= maxNodesAtHeight / 2) 
    {
        return (1 << h) - 1; // Full left subtree
    } 
    else 
    {
        return (1 << h) - 1 - (maxNodesAtHeight / 2 - lastLevelNodes);
    }
}

int countMaxHeaps(int A) 
{
    if (A <= 1) return 1;

    if (dp[A] != -1) return dp[A];

    int left = getLeftSubtreeSize(A);
    int right = A - 1 - left;

    long long ans = (long long)comb[A - 1][left] * countMaxHeaps(left) % MOD;
    ans = ans * countMaxHeaps(right) % MOD;

    return dp[A] = ans;
}

int Solution::solve(int A) 
{
    dp.resize(A + 1, -1);
    calculateCombinations(A);
    return countMaxHeaps(A);
}
