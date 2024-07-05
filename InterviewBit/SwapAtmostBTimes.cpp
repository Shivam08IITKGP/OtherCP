vector<int> Solution::solve(vector<int> &A, int B) 
{    
    int n = A.size();
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[A[i]] = i;
    }
    for(int i=0;i<n;i++)
    {
        if(B==0)
            break;
        if(A[i]!= n-i)
        {
            int x = A[i];
            A[i] = n-i;
            B--;
            A[mp[n-i]] = x;
            int k = mp[n-i];
            mp[n-i] = i;
            mp[x] = k;
        }
    }   
    return A; 
}
//https://www.interviewbit.com/problems/largest-permutation/submissions/
