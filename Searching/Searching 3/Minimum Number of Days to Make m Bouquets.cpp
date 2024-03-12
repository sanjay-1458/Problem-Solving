class Solution {
    int fun(vector<int>&arr,int mid,int k){
        int cnt=0,ans=0;
        for(int i=0;i<arr.size();++i){
            if(arr[i]<=mid){
                cnt++;
            }
            else{
                ans+=cnt/k;
                cnt=0;
            }
        }
        ans+=cnt/k;
        return ans;
    }
public:
    int minDays(vector<int>& nums, int m, int k) {
        if((long long)m*k>(long long)nums.size()) return -1;
        int mini=nums[0],maxi=nums[0];
        for(int i=0;i<nums.size();++i){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
            if(nums[i]<mini){
                mini=nums[i];
            }
        }
        int low=mini,high=maxi;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int bouq=fun(nums,mid,k);
            if(bouq<m){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        if(low==nums.size()) low=-1;
        return ans;
    }
};
