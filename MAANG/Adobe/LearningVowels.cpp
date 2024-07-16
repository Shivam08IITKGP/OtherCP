/*
Let dp[i][j] be the number of ways to make distinct strings of length i where the last 
j characters of the string are vowels.
So the states of dynamic programming are:
If j = 0, then dp[i][j] = (dp[i-1][0] + dp[i-1][1] +……+ dp[i-1][K])*21
(represented by the integer variable sum) because the last added character 
should be a consonant, then only the value of j will become 0, irrespective 
of its value on previous states.

If i<j, then dp[i][j] = 0. Since it is not possible to create a string containing
j vowels and has a length less than j.

If i == j, then dp[i][j] = 5i because the number of characters in the string is
equal to the number of vowels, therefore all the characters should be vowels.

If j<i, then dp[i][j] = dp[i-1][j-1]*5 because a string of length i with the last j 
characters vowel can be made only if the last character is the vowel, and the
string of length i-1 has last j – 1 character as vowels.
Print the sum of dp[n][0] + dp[n][1] + …… + dp[n][K] as the answer.
*/
void solve()
{
    int n, k;
    cin>>n>>k;
    vector<vector<int>>dp(n+1, vector<int>(k+1, 0));

    dp[0][0] = 1;
    int sum = 1;
    for(int i=1;i<=n;i++)
    {
        dp[i][0] = (sum*21)%N;
        sum = dp[i][0];
        for(int j=1;j<=k;j++)
        {
            if(j>i)
            {
                dp[i][j] = 0;
            }
            else if(i==j)
            {
                dp[i][j] = binpow(5, i, N);
            }
            else
            {
                dp[i][j] = dp[i-1][j-1]*5;
            }
            dp[i][j]%=N;
            sum+=dp[i][j];
            sum%=N;
        }        
    }
    cout<<sum<<endl;
}
