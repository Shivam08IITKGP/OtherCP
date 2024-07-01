int Solution::maxProfit(const vector<int> &A) 
{
    vector<int>curr(2,0);
    vector<int>next(2,0);
    int n = A.size();
    for(int index = n-1;index>=0;index--)
    {
        for(int buy=0;buy<2;buy++)
        {
            int profit=0;
            if(buy)
            {
                int buyKaro = -A[index] + next[0];
                int skpKaro = next[1]; 
                profit = max(buyKaro,skpKaro);
            }
            else
            {
                int sellKaro = A[index]+next[1];
                int skpKaro = next[0];
                profit = max(sellKaro,skpKaro );
            }
            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
    
}
