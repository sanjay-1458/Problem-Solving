class Solution {
public:
    int search(vector<int>& nums, int k) {
        int ans=-1;
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==k){
                return mid;
            }
            else if(nums[low]<=nums[mid]){
                if(nums[low]<=k && k<nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(nums[mid]<k && k<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};