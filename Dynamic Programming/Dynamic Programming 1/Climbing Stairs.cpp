// Recursion
class Solution {
    int fun(int n,int sum){
        if(sum==n){
            return 1;
        }
        if(sum>n){
            return 0;
        }
        return fun(n,sum+1)+fun(n,sum+2);
    }
public:
    int climbStairs(int n) {
        return fun(n,0);
    }
};

// Meomization
class Solution {
    int fun(int n,vector<int>&dp){
        if(n<=2){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=fun(n-1,dp)+fun(n-2,dp);
        return dp[n];
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return fun(n,dp);
    }
};

// Tabulation
class Solution {
public:
    int climbStairs(int n) {
        int *arr=new int[n+1];
        arr[0]=1;
        for(int i=1;i<=n;++i){
            arr[i]=arr[i-1];
            if(i-2>=0){
                arr[i]+=arr[i-2];
            }
        }
        return arr[n];
    }
};


// Space Optimization
class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        int prev2=1,prev1=2;
        for(int i=3;i<=n;++i){
            int curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};
