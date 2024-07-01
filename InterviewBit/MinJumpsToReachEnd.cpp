int Solution::jump(vector<int> &A) 
{
    int n = A.size();
    if (n <= 1) return 0;

    int jumps = 0;       // number of jumps
    int farthest = 0;    // the farthest index we can reach
    int currentEnd = 0;  // the end of the current jump

    for (int i = 0; i < n - 1; ++i) 
    {
        farthest = max(farthest, i + A[i]);
        
        // If we have reached the end of the current jump range
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;

            // If the current end is beyond or at the last index
            if (currentEnd >= n - 1) {
                return jumps;
            }
        }
    }

    // If we never reach the last index
    return -1;
}
