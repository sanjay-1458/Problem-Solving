class Solution {
public:
    vector<int> dp;
    int helper(int n){
        if(n==0 || n==1) return 1;
        if(n==2) return 2;
        if(dp[n]!=-1) return dp[n];
        int ans = 0;
        
        for(int i=1; i<=n; i++){
            ans = ans + helper(i-1)*helper(n-i);
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        dp.resize(20,-1);
        return helper(n);
    }
};

public:
    //Function to return the total number of possible unique BST. 
    int numTrees(int N) 
    {
        // Your code here
        const int MOD=(int)1e9+7;
        vector<long long> dp(N+1,0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= N; i++) {
            for (int j = 1; j <= i; j++)
                dp[i] = (dp[i] + (dp[j-1] * dp[i - j])%MOD)%MOD;
        }

        return dp[N];
    }
