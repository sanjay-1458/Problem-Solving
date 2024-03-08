class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=nums[nums.size()-1];
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(nums[mid]<nums[high]){
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
            else{
                ans=min(ans,nums[low]);
                low=mid+1;
            }
        }
        return ans;
    }
};