// Recursion
class Solution {
    int fun(int ind,vector<int>&nums){
        if(ind==0){
            return nums[0];
        }
        if(ind<0){
            return 0;
        }
        int pick=0,notpick=0;
        notpick=fun(ind-1,nums);
        pick=nums[ind]+fun(ind-2,nums);
        return max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        return fun(n-1,nums);
    }
};


// Memoization
class Solution {
    int fun(int ind,vector<int>&dp,vector<int>&nums){
        if(ind==0){
            return nums[0];
        }
        if(ind<0){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        int pick=0,notpick=0;
        notpick=fun(ind-1,dp,nums);
        pick=nums[ind]+fun(ind-2,dp,nums);
        return dp[ind]=max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return fun(n-1,dp,nums);
    }
};

// Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;++i){
            if(i==1){
                dp[1]=max(nums[0],nums[1]);
                continue;
            }
            int pick=0,notpick=0;
            notpick=dp[i-1];
            pick=nums[i]+dp[i-2];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }
};

// Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev2=nums[0];
        int prev1=0;
        for(int i=1;i<n;++i){
            if(i==1){
                prev1=max(nums[0],nums[1]);
                continue;
            }
            int pick=0,notpick=0;
            notpick=prev1;
            pick=nums[i]+prev2;
            int curr=max(pick,notpick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};
