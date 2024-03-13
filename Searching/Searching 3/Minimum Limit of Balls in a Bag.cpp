class Solution {
public:
    bool fun(vector<int>& nums, int mx, int p)
    {
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i]/p;
            if(nums[i]%p==0)
                x--;
            res+=x;
        }
        return res<=mx;
    }
    int minimumSize(vector<int>& nums, int mx) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
       
        int ans=high;
        while(low<=high)
        {
            int p=low+(high-low)/2;
           
            if(fun(nums, mx, p))
            {
                ans=min(ans, p);
                high=p-1;
            }
            else
            {
                low=p+1;
            }
        }
        return ans;
    }
};
