// Recursion
class Solution {
    int fun(int i,int k,vector<int>&coins){
        int n=coins.size();
        if(i==n){
            if(k==0){
                return 0;
            }
            else{
                return 1e9;
            }
        }
        int pick=1e9;
        int notpick=fun(i+1,k,coins);
        if(coins[i]<=k){
            pick=fun(i,k-coins[i],coins)+1;
        }
        return min(pick,notpick);
    }
public:
    int coinChange(vector<int>& coins, int k) {
        int x=fun(0,k,coins);
        if(x==1e9) return -1;
        else return x;
    }
};

// Memoization
class Solution {
    int fun(int i,int k,vector<int>&coins,vector<vector<int>> &dp){
        int n=coins.size();
        if(i==n){
            if(k==0){
                return 0;
            }
            else{
                return 1e9;
            }
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        int pick=1e9;
        int notpick=fun(i+1,k,coins,dp);
        if(coins[i]<=k){
            pick=fun(i,k-coins[i],coins,dp)+1;
        }
        return dp[i][k]=min(pick,notpick);
    }
public:
    int coinChange(vector<int>& coins, int k) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        int x=fun(0,k,coins,dp);
        if(x==1e9) return -1;
        else return x;
    }
};

// Tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int k) {
        int n=coins.size();
        vector<long long> dp(k+1,1e9);
        dp[0]=0;
        for(int i=1;i<=k;++i){
            for(int j=0;j<n;++j){
                if(i-coins[j]>=0){
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
                }
            }
        }
        return dp[k]==1e9?-1:dp[k];
    }
};
