// Recursion
class Solution {
    long long fun(int i,vector<vector<int>>& questions){
        int n=questions.size();
        if (i == questions.size())
            return 0;
        long long points = questions[i][0];
        long long bp = questions[i][1];
        long long j = min(i + bp + 1,n*1LL);
        return  max(fun(i+1,questions), fun(j,questions) + points);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        return fun(0,questions);
    }
};

// Meomization
class Solution {
    long long fun(int i,vector<vector<int>>& questions,vector<long long> &dp){
        int n=questions.size();
        if (i == questions.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        long long points = questions[i][0];
        long long bp = questions[i][1];
        long long j = min(i + bp + 1,n*1LL);
        return dp[i]= max(fun(i+1,questions,dp), fun(j,questions,dp) + points);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1,-1);
        return fun(0,questions,dp);
    }
};

// Tabultaion
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for (long long i = n - 1; i >= 0; --i) {
            long long val = questions[i][0];
            long long bp = questions[i][1];
            long long j = min(i + bp + 1, n*1LL);

            dp[i] = max(dp[i + 1], dp[j] + val);
        }
        return dp[0];
    }
};
