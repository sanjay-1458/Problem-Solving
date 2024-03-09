class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1;
        if(n==1 || nums[0]>nums[1]) return 0;
        while(l<=h){
            int m=(l+h)/2;
            if(m==n-1) return m;
            if(nums[m+1]<nums[m] && nums[m]>nums[m-1]) return m;
            if(nums[m]<nums[m+1]){
                l=m+1;
            }
            else{
                h=m-1;;
            }
        }
        return -1;
    }
};
