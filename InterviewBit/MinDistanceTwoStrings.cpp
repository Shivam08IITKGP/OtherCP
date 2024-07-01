int Solution::minDistance(string A, string B) 
{
    int n = A.size();
    int m = B.size();
    
    // DP table to store the minimum edit distance
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    // Initialize base cases
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i;  // Cost of converting string A of length i to an empty string
    }
    for (int j = 0; j <= m; ++j) {
        dp[0][j] = j;  // Cost of converting an empty string to string B of length j
    }
    
    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // Characters match, no additional cost
            } else {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                // Minimum of replace, delete from A, or insert into A plus one operation
            }
        }
    }
    
    // The answer is the minimum edit distance between the entire strings
    return dp[n][m];
}
