// Recursion
class Solution {
    int fun(int i,int j,int &n,int &m){
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(i<0 || i>=n || j<0 || j>=m){
            return 0;
        }
        int right=fun(i,j+1,n,m);
        int left=fun(i+1,j,n,m);
        return left+right;
    }
public:
    int uniquePaths(int n, int m) {
        return fun(0,0,n,m);
    }
};

// Memoization
class Solution {
    int fun(int i,int j,int &n,int &m,vector<vector<int>> &dp){
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(i<0 || i>=n || j<0 || j>=m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=fun(i,j+1,n,m,dp);
        int left=fun(i+1,j,n,m,dp);
        return dp[i][j]=left+right;
    }
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return fun(0,0,n,m,dp);
    }
};

// Tabulation
class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0]=1;
        for(int i=1;i<m;++i){
            dp[0][i]=1;
        }
        for(int j=1;j<n;++j){
            dp[j][0]=1;
        }
        for(int i=1;i<n;++i){
            for(int j=1;j<m;++j){
                int up=dp[i-1][j];
                int left=dp[i][j-1];
                dp[i][j]=up+left;
            
            }
        }
        return dp[n-1][m-1];
    }
};
