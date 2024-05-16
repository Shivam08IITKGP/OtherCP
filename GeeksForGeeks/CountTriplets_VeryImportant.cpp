int countTriplets(vector<int>nums)
	{
	    // Code here.
	    int n= nums.size();
	    int ans = 0;
	    for(int i=0;i<n;i++)
	    {
	        int l = 0,r=0;
	        for(int j=0;j<i;j++)
	        {
	            if(nums[j]<nums[i]) l++;
	        }
	        for(int j=i+1;j<n;j++)
	        {
	            if(nums[j]>nums[i]) r++;
	        }
	        ans+=l*r;
	    }
	    return ans;
	}
