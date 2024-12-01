// Basically
// if n = 4m      ->        n = 1^2^.....^n
// if n = 4m + 1  ->        n = 1^2^.....^n-2^n
// if n = 4m + 2  ->        n = 2^3^.....^n
// if n = 4m + 3  ->        n = 1^2^.....^n-1
class Solution {
  public:
    vector<int> subsetXOR(int n) {
        // code here
        int l = 1; int h = n;
        
        int mod = n%4;
        
        switch(mod)
        {
            case 1:
                h -= 2;
                break;
            case 2:
                l++;
                break;
            case 3:
                h--;
                break;
        }
        vector<int> res;
        for(int i = l; i <= h; i++)
        {
                res.push_back(i);
        }  
        if(mod == 1) res.push_back(n);
        return res;
    }
};
