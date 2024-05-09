// Recursion
class Solution {
    int fun(int i,vector<int>& nums,bool picked){
        int n=nums.size();
        if(i==n){
            if(picked==false){
                return INT_MIN;
            }
            else{
                return 0;
            }
        }
        int pick=INT_MIN,notpick=INT_MIN;
        if(picked==false){
            notpick=fun(i+1,nums,false);
            pick=nums[i]+fun(i+1,nums,true);
        }
        else{
            pick=nums[i]+fun(i+1,nums,true);
            notpick=0;
        }
        return max(pick,notpick);
    }
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        return fun(0,nums,false);
    }
};

// Memoization
class Solution {
    int fun(int i,vector<int>& nums,bool picked,vector<vector<int>> &dp){
        int n=nums.size();
        if(i==n){
            if(picked==false){
                return INT_MIN;
            }
            else{
                return 0;
            }
        }
        if(dp[i][picked]!=INT_MIN) return dp[i][picked];
        int pick=INT_MIN,notpick=INT_MIN;
        if(picked==false){
            notpick=fun(i+1,nums,false,dp);
            pick=nums[i]+fun(i+1,nums,true,dp);
        }
        else{
            pick=nums[i]+fun(i+1,nums,true,dp);
            notpick=0;
        }
        return dp[i][picked]=max(pick,notpick);
    }
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2,INT_MIN));
        return fun(0,nums,false,dp);
    }
};

// Tabulation
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2));
        dp[n][0]=INT_MIN;
        dp[n][1]=0;
        for(int i=n-1;i>=0;--i){
            for(int j=0;j<=1;++j){
                int pick=INT_MIN,notpick=INT_MIN;
                if(j==0){
                    notpick=dp[i+1][0];
                    pick=nums[i]+dp[i+1][1];
                }
                else{
                    pick=nums[i]+dp[i+1][1];
                    notpick=0;
                }
                dp[i][j]=max(pick,notpick);
            }

        }
        return dp[0][0];
    }
};
