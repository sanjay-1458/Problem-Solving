// Recursion
class Solution {
    int fun(int i,int cnt,int prev,vector<int>&nums,int &lis){
        int n=nums.size();
        if(cnt==lis){
            return 1;
        }
        if(i>=n) return 0;
        int notpick=fun(i+1,cnt,prev,nums,lis);
        int pick=0;
        if(prev==-1 || nums[prev]<nums[i]){
            pick=fun(i+1,cnt+1,i,nums,lis);
        }
        return pick+notpick;
    }
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j] && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int ans=0;
        return fun(0,0,-1,nums,maxi);
    }
};

// Memoization
class Solution {
    int fun(int i,int cnt,int prev,vector<int>&nums,int &lis,vector<vector<vector<int>>> &memo){
        int n=nums.size();
        if(cnt==lis){
            return 1;
        }
        if(i>=n) return 0;
        if(memo[i][cnt][prev]!=-1) return memo[i][cnt][prev];
        int notpick=fun(i+1,cnt,prev,nums,lis,memo);
        int pick=0;
        if(prev==0 || nums[prev-1]<nums[i]){
            pick=fun(i+1,cnt+1,i+1,nums,lis,memo);
        }
        return memo[i][cnt][prev]=pick+notpick;
    }
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j] && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int ans=0;
        vector<vector<vector<int>>> memo(n,vector<vector<int>>(maxi+1,vector<int>(n+1,-1)));
        return fun(0,0,0,nums,maxi,memo);
    }
};
// Tabulation
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int maxi=1;
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[j]>=nums[i]) continue;
                if(dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    cnt[i]=cnt[j];
                }
                else if(dp[i]==1+dp[j]){
                    cnt[i]+=cnt[j];
                }
                maxi=max(maxi,dp[i]);
            }
        }
        int ans=0;
        for(int i=0;i<n;++i){
            if(dp[i]==maxi){
                ans+=cnt[i];
            }
        }
        return ans;
    }
};
