int Solution::longestValidParentheses(string A) 
{
    int n = A.size();
    stack<int>s;
    s.push(-1);
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(A[i]=='(')
        {
            s.push(i);
        }
        else if(A[i]==')')
        {
            s.pop();
            if(s.empty())
            {
                s.push(i);
                //Replacement of the -1 
                //If we next time encounter a ), then we are
                //going to pop it anyway
                //If We popped a index of ( then in the below loop we 
                //will count the sequence () that is length =2
                //So method is ok
            }
            else if(!s.empty())
            {
                ans = max(ans, i- s.top());
                
            }
        }
    }
    return ans;
    
}
