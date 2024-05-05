// Memoization + Recursion

class Solution {
    int fun(int i,int j,vector<vector<int>>&dungeon,vector<vector<int>> &dp){
        int n=dungeon.size(),m=dungeon[0].size();
        if(i>=n || j>=m) return 1e9;
        if(i==n-1 && j==m-1){
            if(dungeon[i][j]<0){
                return abs(dungeon[i][j])+1;
            }
            else{
                return 1;
            }
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int left=fun(i,j+1,dungeon,dp);
        int right=fun(i+1,j,dungeon,dp);
        int curr=0;
        if(dungeon[i][j]>=0){
            int x=min(left,right)-dungeon[i][j];
            if(x>=0) return dp[i][j]=x;
            else return dp[i][j]=0;
        }
        else{
            int x= min(left,right)+abs(dungeon[i][j]);
            if(x+dungeon[i][j]==0) return dp[i][j]=1+x;
            else{
                return dp[i][j]=x;
            }
        }

    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size(),m=dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int x=fun(0,0,dungeon,dp);
        if(x==0) return 1;
        else return x;
    }
};
// Tabulation
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size(),m=dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m,1));
        for(int i=n-1;i>=0;--i){
            for(int j=m-1;j>=0;--j){
                if(i==n-1 && j==m-1){
                    if(dungeon[i][j]<0){
                        dp[i][j]= abs(dungeon[i][j])+1;
                    }
                    else{
                        dp[i][j]= 1;
                    }
                    continue;
                }
                int left=1e9,right=1e9;
                if(j+1<m){
                    left=dp[i][j+1];
                }
                if(i+1<n){
                    right=dp[i+1][j];
                }
                if(dungeon[i][j]>=0){
                    int x=min(left,right)-dungeon[i][j];
                    if(x>=0) dp[i][j]=x;
                    else dp[i][j]=0;
                }
                else{
                    int x=min(left,right)+abs(dungeon[i][j]);
                    if(x+dungeon[i][j]==0){
                        dp[i][j]=1+x;
                    }
                    else{
                        dp[i][j]=x;
                    }
                }
            }
        }
        int x=dp[0][0];
        if(x==0) return 1;
        else return x;
    }
};
