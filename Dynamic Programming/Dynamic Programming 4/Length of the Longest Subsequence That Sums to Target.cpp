class Solution {
    int dp[1002][1002];
    int fun(vector<int>&nums,int target,int i){
        if(target==0) return 0;
        if(i>=nums.size()) return -1*1e5;
        if(dp[i][target]!=-1) return dp[i][target];
        if(target>=nums[i])
            return dp[i][target]=max(fun(nums,target,i+1),1+fun(nums,target-nums[i],i+1));
        return dp[i][target]=fun(nums,target,i+1);
    }
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int ans=fun(nums,target,0);
        return ans<0?-1:ans;
    }
};

