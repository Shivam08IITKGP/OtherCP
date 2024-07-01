// https://www.interviewbit.com/problems/interleaving-strings/

int Solution::isInterleave(string A, string B, string C) 
{
    if(A.empty() and B.empty() and C.empty())
    {
        return true;
    }
    if(C.empty())
    {
        return false;
    }
    return ((C[0]==A[0] and isInterleave(A.substr(1),B,C.substr(1))) or (C[0]==B[0] and isInterleave(A,B.substr(1),C.substr(1))));
    
}
