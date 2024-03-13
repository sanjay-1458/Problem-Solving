class Solution {
    bool check(int maxi,vector<int>&nums,int cost){
        int temp=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]<=maxi){
                continue;
            }
            else{
                temp+=nums[i]/maxi;
                if(nums[i]%maxi==0) temp--;
                
            }
        }
        if(temp>cost) return false;
        else return true;
    }
public:
    int minimumSize(vector<int>& nums, int mx) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2; // penalty
            if(check(mid,nums,mx)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
