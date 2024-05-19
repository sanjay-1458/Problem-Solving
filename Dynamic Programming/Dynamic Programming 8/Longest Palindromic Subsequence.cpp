// Memo + Recursion
class Solution {
    int lps(string&s ,int l,int h,vector<vector<int>>& dp){
        if(l>h) return 0;
        if(l==h) return 1;
        if(dp[l][h]!=-1) return dp[l][h];
        if(s[l]==s[h]){
            return dp[l][h]=2+lps(s,l+1,h-1,dp);
        }
        else{
            return dp[l][h]=max(lps(s,l+1,h,dp),lps(s,l,h-1,dp));
        }
    }
public:
    int longestPalindromeSubseq(string s) {
        int l=0,h=(int)s.size()-1;
        vector<vector<int>> dp(h+1,vector<int>(h+1,-1));
        return lps(s,l,h,dp);
    }
};

// Tabulation
class Solution {
    int lps(string&s ,int l,int h,vector<vector<int>>& dp){
        if(l>h) return 0;
        if(l==h) return 1;
        if(dp[l][h]!=-1) return dp[l][h];
        if(s[l]==s[h]){
            return dp[l][h]=2+lps(s,l+1,h-1,dp);
        }
        else{
            return dp[l][h]=max(lps(s,l+1,h,dp),lps(s,l,h-1,dp));
        }
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + (len == 2 ? 0 : dp[i + 1][j - 1]);
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};
