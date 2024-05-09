// Recursion
class Solution {
    int min(int a,int b){
        if(a<b) return a;
        else return b;
    }
    int fun(int i,int j,vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m){
            return (int)1e9;
        }
        if(i==n-1 && j==m-1){
            return grid[i][j];
        }
        int right=fun(i,j+1,grid)+grid[i][j];
        int down=fun(i+1,j,grid)+grid[i][j];
        return min(right,down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        // fun(i,j) returns the minimum path cost to reach from i,j to n-1,m-1
        return fun(0,0,grid);
    }
};

// Memoization
class Solution {
    int min(int a,int b){
        if(a<b) return a;
        else return b;
    }
    int fun(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        int n=grid.size(),m=grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m){
            return (int)1e9;
        }
        if(i==n-1 && j==m-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int right=fun(i,j+1,grid,dp)+grid[i][j];
        int down=fun(i+1,j,grid,dp)+grid[i][j];
        return dp[i][j]=min(right,down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        // fun(i,j) returns the minimum path cost to reach from i,j to n-1,m-1
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return fun(0,0,grid,dp);
    }
};

// Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        // dp[i][j] returns the minimum path cost to reach from 0,0 to i,j
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else{
                    int up=1e9,left=1e9;
                    if(i>0){
                        up=grid[i][j]+dp[i-1][j];
                    }
                    if(j>0){
                        left=grid[i][j]+dp[i][j-1];
                    }
                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};


// Space Optimization
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> prev(m,0);
        for(int i=0;i<n;++i){
            vector<int> curr(m,0);
            for(int j=0;j<m;++j){
                if(i==0 && j==0) curr[j]=grid[i][j];
                else{
                    int up=1e9,left=1e9;
                    if(i>0){
                        up=grid[i][j]+prev[j];
                    }
                    if(j>0){
                        left=grid[i][j]+curr[j-1];
                    }
                    curr[j]=min(up,left);
                }
            }
            prev=curr;
        }
        return prev[m-1];
    }
};
