int Solution::cnttrue(string A) 
{
    int n = A.size();
    vector<vector<int>> dp_true(n, vector<int>(n, 0));
    vector<vector<int>> dp_false(n, vector<int>(n, 0));
    int MOD = 1003;
    
    // Initialization: Base cases
    for (int i = 0; i < n; i++) {
        if (A[i] == 'T') {
            dp_true[i][i] = 1;
            dp_false[i][i] = 0;
        } else if (A[i] == 'F') {
            dp_true[i][i] = 0;
            dp_false[i][i] = 1;
        }
    }
    
    // Fill DP tables
    for (int len = 3; len <= n; len += 2) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            for (int k = i + 1; k < j; k += 2) {
                char op = A[k];
                
                int left_true = dp_true[i][k-1];
                int left_false = dp_false[i][k-1];
                int right_true = dp_true[k+1][j];
                int right_false = dp_false[k+1][j];
                
                if (op == '&') {
                    dp_true[i][j] += (left_true * right_true) % MOD;
                    dp_false[i][j] += (left_true * right_false) % MOD + (left_false * right_true) % MOD + (left_false * right_false) % MOD;
                } else if (op == '|') {
                    dp_true[i][j] += (left_true * right_true) % MOD + (left_true * right_false) % MOD + (left_false * right_true) % MOD;
                    dp_false[i][j] += (left_false * right_false) % MOD;
                } else if (op == '^') {
                    dp_true[i][j] += (left_true * right_false) % MOD + (left_false * right_true) % MOD;
                    dp_false[i][j] += (left_true * right_true) % MOD + (left_false * right_false) % MOD;
                }
                
                dp_true[i][j] %= MOD;
                dp_false[i][j] %= MOD;
            }
        }
    }
    
    return dp_true[0][n-1];
}
