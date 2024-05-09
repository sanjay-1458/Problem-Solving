// Rcursion
class Solution {
    int fun(int i,int k,vector<int>&coins){
        int n=coins.size();
        if(i==n){
            if(k==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        int pick=0;
        int notpick=fun(i+1,k,coins);
        if(coins[i]<=k){
            pick=fun(i,k-coins[i],coins);
        }
        return pick+notpick;
    }
public:
    int change(int k, vector<int>& coins) {
        return fun(0,k,coins);
    }
};

// Memoization
class Solution {
    int fun(int i,int k,vector<int>&coins,vector<vector<int>> &dp){
        int n=coins.size();
        if(i==n){
            if(k==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        int pick=0;
        int notpick=fun(i+1,k,coins,dp);
        if(coins[i]<=k){
            pick=fun(i,k-coins[i],coins,dp);
        }
        return dp[i][k]=pick+notpick;
    }
public:
    int change(int k, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return fun(0,k,coins,dp);
    }
};

// Tabulation
class Solution {
public:
    int change(int sum, vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        for(int i=0;i<n;++i){
            dp[i][0]=1;
        }
        for(int j=0;j<=sum;++j){
            if(arr[0]==j){
                dp[0][arr[0]]=1;
            }
            else if(j%arr[0]==0){
                dp[0][j]=1;
            }
        }
        for(int i=1;i<n;++i){
            for(int j=1;j<=sum;++j){
                long exclude=dp[i-1][j];
                long include=0;
                if(j-arr[i]>=0){
                    include=dp[i][j-arr[i]];
                }
                dp[i][j]=include+exclude;
            }
        }
        return dp[n-1][sum];
    }
};
