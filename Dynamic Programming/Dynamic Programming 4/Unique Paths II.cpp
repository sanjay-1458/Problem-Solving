
// Recursion
class Solution {
    int fun(int i,int j,vector<vector<int>>&mat){
        int n=mat.size(),m=mat[0].size();
        if(i<0 || i>=n || j<0 || j>=m){
            return 0;
        }
        if(mat[i][j]==1){
            return 0;
        }
        if(i==n-1 && j==m-1){
            return 1;
        }
        int right=fun(i,j+1,mat);
        int down=fun(i+1,j,mat);
        return (right+down);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        return fun(0,0,mat);
    }
};

// Memoization
class Solution {
    int fun(int i,int j,vector<vector<int>>&mat,vector<vector<int>> &dp){
        int n=mat.size(),m=mat[0].size();
        if(i<0 || i>=n || j<0 || j>=m){
            return 0;
        }
        if(mat[i][j]==1){
            return 0;
        }
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=fun(i,j+1,mat,dp);
        int down=fun(i+1,j,mat,dp);
        return dp[i][j]=(right+down);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return fun(0,0,mat,dp);
    }
};

// Tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n=arr.size(),m=arr[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(i==0 && j==0 && arr[i][j]==0) dp[i][j]=1;
                else if(arr[i][j]==1){
                    dp[i][j]=0;
                }
                else{
                    if(i>0)
                    dp[i][j]+=dp[i-1][j];
                    if(j>0)
                    dp[i][j]+=dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};
