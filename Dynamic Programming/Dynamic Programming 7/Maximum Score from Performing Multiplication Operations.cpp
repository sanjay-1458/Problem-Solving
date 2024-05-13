// Recursion
class Solution {
public:
    int f(vector<int>& nums, vector<int>& mul, int ind, int i, int j) {
        int n = nums.size(), m = mul.size();
        if (ind == m) return 0;

        int scoreLeft = (i < n) ? nums[i] * mul[ind] + f(nums, mul, ind + 1, i + 1, j) : INT_MIN;
        int scoreRight = (j >= 0) ? nums[j] * mul[ind] + f(nums, mul, ind + 1, i, j - 1) : INT_MIN;

        return max(scoreLeft, scoreRight);
    }

    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int n = nums.size(), m = mul.size();
        return f(nums, mul, 0, 0, n - 1);
    }
};

// Memoization
class Solution {
public:
    int f(vector<int>& nums, vector<int>& mul,int ind, int i,int j,vector<vector<int>>& dp){
        int n = nums.size(), m = mul.size();
        if(ind==m) return 0;
        if(dp[i][ind] !=INT_MIN) return dp[i][ind];
        return dp[i][ind]= max((nums[i] *mul[ind]) + f(nums,mul,ind+1,i+1,j,dp),(nums[j] *mul[ind]) + f(nums,mul,ind+1,i,j-1,dp));
    }
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int n = nums.size(), m = mul.size();
        vector<vector<int>> dp(m+1,vector<int>(vector<int>(n+1,INT_MIN)));
        return f(nums,mul,0,0,n-1,dp);
    }
};

// Tabulation
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int n = nums.size(), m = mul.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, INT_MIN));
        dp[0][0] = 0;

        for (int len = 1; len <= m; ++len) {
            for (int i = 0; i <= len; ++i) {
                int j = len - i;

                int scoreLeft = (i > 0) ? nums[i - 1] * mul[len - 1] + dp[len - 1][i - 1] : INT_MIN;
                int scoreRight = (j > 0) ? nums[n - j] * mul[len - 1] + dp[len - 1][i] : INT_MIN;

                dp[len][i] = max(scoreLeft, scoreRight);
            }
        }

        int maxScore = INT_MIN;
        for (int i = 0; i <= m; ++i) {
            maxScore = max(maxScore, dp[m][i]);
        }
        return maxScore;
    }
};
