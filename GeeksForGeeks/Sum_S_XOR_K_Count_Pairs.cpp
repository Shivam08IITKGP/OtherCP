// C++ program to count ordered pairs of
// positive numbers such that their
// sum is S and XOR is K
 
#include <bits/stdc++.h>
using namespace std;
 
// Function to count ordered pairs of
// positive numbers such that their
// sum is S and XOR is K
int countPairs(int s, int K)
{
    // Check if no such pair exists
    if (K > s || (s - K) % 2) {
        return 0;
    }
 
    if ((s - K) / 2 & K) {
        return 0;
    }
 
    // Calculate set bits in K
    int setBits = __builtin_popcount(K);
 
    // Calculate pairs
    int pairsCount = pow(2, setBits);
 
    // If s = k, subtract 2 from result
    if (s == K)
        pairsCount -= 2;
 
    return pairsCount;
}
 
// Driver code
int main()
{
    int s = 9, K = 5;
 
    cout << countPairs(s, K);
 
    return 0;
}
