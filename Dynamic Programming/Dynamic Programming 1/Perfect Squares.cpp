// Recursion
class Solution {
    int fun(int n){
        if(n==0) return 0;
        int ans=1e6;
        for(int i=1;i*i<=n;++i){
            int cnt=fun(n-i*i)+1;
            ans=min(ans,cnt);
        }
        return ans;
    }
public:
    int numSquares(int n) {
        return fun(n);
    }
};
// Memoization
class Solution {
    int fun(int n,vector<int>& dp){
        if(n==0) return 0;
        int ans=1e6;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i*i<=n;++i){
            int cnt=fun(n-i*i,dp)+1;
            ans=min(ans,cnt);
        }
        return dp[n]=ans;
    }
public:
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return fun(n,dp);
    }
};
// Tabulation
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        dp[0]=0;
        for(int i=1;i<=n;++i){
            int ans=1e7;
            for(int j=1;j*j<=i;++j){
                int cnt=dp[i-j*j]+1;
                ans=min(ans,cnt);
            }
            dp[i]=ans;
        }
        return dp[n];
    }
};
