// Recursion
class Solution {
    const int mod=(int)1e9+7;
    int fun(int i,int &k,int sum){
        if(i==0 && sum==0){
            return 1;
        }
        if(i==0 || sum<0){
            return 0;
        }
        int ans=0;
        for(int j=1;j<=k;++j){
            if(sum-i>=0){
                ans=(fun(i-1,k,sum-j)%mod+ans)%mod;
            }
        }
        return ans;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        return fun(n,k,target);

    }
};

// Memoization
class Solution {
    const int mod=(int)1e9+7;
    int fun(int i,int &k,int sum,vector<vector<int>> &dp){
        if(i==0 && sum==0){
            return 1;
        }
        if(i==0 || sum<0){
            return 0;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int ans=0;
        for(int j=1;j<=k;++j){
            if(sum-i>=0){
                ans=(fun(i-1,k,sum-j,dp)%mod+ans)%mod;
            }
        }
        return dp[i][sum]=ans;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return fun(n,k,target,dp);

    }
};

// Tabulation
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int mod=(int)1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        for(int i=0;i<=n;++i){
            for(int sum=0;sum<=target;++sum){
                if(i==0 && sum==0){
                    dp[i][sum]=1;
                }
                else if(i==0){
                    dp[i][sum]=0;
                }
                else{
                    int ans=0;
                    for(int j=1;j<=k;++j){
                        if(sum-j>=0){
                            ans=((dp[i-1][sum-j])%mod+ans)%mod;
                        }
                    }
                    dp[i][sum]=ans;
                }
            }
        }
        return dp[n][target];
    }
};
