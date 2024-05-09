
// Recursion
class Solution {
    int fun(int i,int j,vector<vector<int>>& grid, vector<vector<int>>& cost){
        int n=grid.size(),m=grid[0].size();
        if(i==n-1){
            return 0;
        }
        int ans=1e9;
        for(int k=0;k<m;++k){
            int val=fun(i+1,k,grid,cost)+cost[grid[i][j]][k]+grid[i+1][k];
            ans=min(ans,val);
        }
        return ans;
    }
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& cost) {
        int ans=1e9;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<m;++i){
            ans=min(ans,fun(0,i,grid,cost)+grid[0][i]);
        }
        return ans;
    }
};

// Meomoization
class Solution {
    int fun(int i,int j,vector<vector<int>>& grid, vector<vector<int>>& cost,vector<vector<int>> &dp){
        int n=grid.size(),m=grid[0].size();
        if(i==n-1){
            return 0;
        }
        int ans=1e9;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        for(int k=0;k<m;++k){
            int val=fun(i+1,k,grid,cost,dp)+cost[grid[i][j]][k]+grid[i+1][k];
            ans=min(ans,val);
        }
        return dp[i][j]=ans;
    }
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& cost) {
        int ans=1e9;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<m;++i){
            ans=min(ans,fun(0,i,grid,cost,dp)+grid[0][i]);
        }
        return ans;
    }
};

// Tabulation
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& cost) {
        int ans=1e9;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=n-2;i>=0;--i){
            for(int j=0;j<m;++j){
                int ans=1e9;
                for(int k=0;k<m;++k){
                    int val=dp[i+1][k]+cost[grid[i][j]][k]+grid[i+1][k];
                    ans=min(ans,val);
                }
                dp[i][j]=ans;
            }
        }
        int res=1e9;
        for(int j=0;j<m;++j){
            res=min(res,dp[0][j]+grid[0][j]);
        }
        return res;
    }
};

// Space Optimization
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& cost) {
        int ans=1e9;
        int n=grid.size(),m=grid[0].size();
        vector<int> next(m,0);
        for(int i=n-2;i>=0;--i){
            vector<int> curr(m,0);
            for(int j=0;j<m;++j){
                int ans=1e9;
                for(int k=0;k<m;++k){
                    int val=next[k]+cost[grid[i][j]][k]+grid[i+1][k];
                    ans=min(ans,val);
                }
                curr[j]=ans;
            }
            next=curr;
        }
        int res=1e9;
        for(int j=0;j<m;++j){
            res=min(res,next[j]+grid[0][j]);
        }
        return res;
    }
};
