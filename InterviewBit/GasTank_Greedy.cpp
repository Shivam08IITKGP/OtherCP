int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int total = 0;
    int n = A.size();
    for(int i=0;i<A.size();i++) total += (A[i]-B[i]);
    if(total <= -1) return -1;
   
    int cum_sum = 0;
    int index = 0;
    for(int i=0;i<n;i++){
        cum_sum += (A[i]-B[i]);
        if(cum_sum < 0) {
            cum_sum = 0;
            index = i+1;
        }
    }
    return cum_sum < 0 ? -1 : index;
}
// https://www.interviewbit.com/problems/gas-station/discussion/p/simple-greedy-approach-tc-o-n-sc-o-1/307070/374/
