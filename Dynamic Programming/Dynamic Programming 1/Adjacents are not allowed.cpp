// Tabulation
class Solution{
public:
  int solve(int n,vector<vector<int>>&mat,int r,int c){

        if(c>=n)return 0;

        int t1=mat[r][c]+max(solve(n,mat,1,c+2),solve(n,mat,0,c+2));
        int t2=solve(n,mat,1,c+1);
        int t3=solve(n,mat,0,c+1);
        return max(t1,max(t2,t3));
    }

    int maxSum(int n, vector<vector<int>> mat)

    {
        return max(solve(n,mat,0,0),solve(n,mat,1,0));
    }
};

// Memoization
class Solution{
public:
  int solve(int n,vector<vector<int>>&mat,int r,int c,vector<vector<int>> &dp){

        if(c>=n)return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        int t1=mat[r][c]+max(solve(n,mat,1,c+2,dp),solve(n,mat,0,c+2,dp));
        int t2=solve(n,mat,1,c+1,dp);
        int t3=solve(n,mat,0,c+1,dp);
        return dp[r][c]=max(t1,max(t2,t3));
    }

    int maxSum(int n, vector<vector<int>> mat)

    {
        vector<vector<int>> dp(3,vector<int>(n+1,-1));
        return max(solve(n,mat,0,0,dp),solve(n,mat,1,0,dp));
    }
};


