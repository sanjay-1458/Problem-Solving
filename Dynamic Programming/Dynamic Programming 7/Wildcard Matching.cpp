// Resursion
class Solution {
public:
    bool fun(const string& s, const string& t, int i, int j) {
        if (i == 0 && j == 0) {
            return true;
        }
        if (j == 0) {
            return false;
        }
        if (i == 0) {
            return t[j - 1] == '*' && fun(s, t, i, j - 1);
        }

        if (s[i - 1] == t[j - 1] || t[j - 1] == '?') {
            return fun(s, t, i - 1, j - 1);
        }

        if (t[j - 1] == '*') {
            return fun(s, t, i, j - 1) || fun(s, t, i - 1, j);
        }

        return false;
    }

    bool isMatch(string s, string t) {
        int n = s.size(), m = t.size();
        return fun(s, t, n, m);
    }
};

// Memoization
class Solution {
public:
    bool fun(const string& s, const string& t, int i, int j, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (i == 0 && j == 0) {
            return true;
        }
        if (j == 0) {
            return false;
        }
        if (i == 0) {
            return t[j - 1] == '*' && fun(s, t, i, j - 1, dp);
        }

        bool result = false;
        if (s[i - 1] == t[j - 1] || t[j - 1] == '?') {
            result = fun(s, t, i - 1, j - 1, dp);
        } else if (t[j - 1] == '*') {
            result = fun(s, t, i, j - 1, dp) || fun(s, t, i - 1, j, dp);
        }

        dp[i][j] = result ? 1 : 0;
        return result;
    }

    bool isMatch(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return fun(s, t, n, m, dp);
    }
};
// Tabulation
class Solution {
public:
    bool isMatch(string t, string s) {
        int n=s.size(),m=t.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int j=1;j<=m;++j){
            dp[0][j]=false;
        }
        for(int i=1;i<=n;++i){
            if(s[i-1]=='*'){
                dp[i][0]=true;
            }
            else{
                break;
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(s[i-1]==t[j-1] || s[i-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    if(s[i-1]=='*'){
                    dp[i][j]=dp[i][j-1] || dp[i-1][j];
                    }
                    else{
                    dp[i][j]=false;
                    }
                }
            }
        }
        return  dp[n][m];
    }
};
