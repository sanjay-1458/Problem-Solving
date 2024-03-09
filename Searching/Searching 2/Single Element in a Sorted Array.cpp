class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1;
        if(n==1) return nums[0];
        while(l<=h){
            int m=(l+h)/2;
            int first=m;
            if(m==0 || m==n-1) return nums[m];
            if(nums[m]!=nums[m-1] && nums[m]!=nums[m+1]) return nums[m];
            if(nums[m]==nums[m-1]){
                first=m-1;
            }
            if(first%2==0){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return -1;
    }
};
