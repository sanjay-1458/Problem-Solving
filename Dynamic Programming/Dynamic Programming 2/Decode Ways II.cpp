// Recursion
class Solution {

public:
    const int M = 1000000007;

    int fun(const string& s, int index) {
        if (index == s.size()) 
            return 1;
        
        char num = s[index];

        if (num == '*') {
            long long ways = 9LL * fun(s, index + 1) % M;

            if (index + 1 < s.size()) {
                if (s[index + 1] == '*') {
                    ways = (ways + 15LL * fun(s, index + 2)) % M;
                } else {
                    if (s[index + 1] <= '6') {
                        ways = (ways + 2LL * fun(s, index + 2)) % M;
                    } else {
                        ways = (ways + fun(s, index + 2)) % M;
                    }
                }
            }

            return ways;
        }
        
        if (num == '0')
            return 0;
        
        long long ways = fun(s, index + 1);

        if (index + 1 < s.size() && s[index + 1] != '*') {
            if ((num == '1') || (num == '2' && s[index + 1] <= '6')) {
                ways = (ways + fun(s, index + 2)) % M;
            }
        } else { 
            if (num == '1') {
                ways = (ways + 9LL * fun(s, index + 2)) % M;
            } else if (num == '2') {
                ways = (ways + 6LL * fun(s, index + 2)) % M;
            }
        }

        return ways;
    }

    int numDecodings(string s) {
        return fun(s, 0);
    }
};

// Memoization
class Solution {
public:
    const int mod = 1000000007;
    vector<long long> dp;
    int n;
    string s;

    int numDecodings(string s) {
        n = s.size();
        this->s = s;
        dp.resize(n, -1);
        return f(0);
    }

    long long int f(int i) {
        if (i >= n) return 1;
        if (s[i] == '0') return 0;
        if (i == n - 1) return (s[i] == '*' ? 9 : 1);
        if (dp[i] != -1) return dp[i];
        long long int ans = 0;
        if (s[i] == '*') {
            ans = (ans + 9 * f(i + 1) % mod) % mod;
            if (s[i + 1] == '*') ans = (ans + 15 * f(i + 2) % mod) % mod;
            else {
                if (s[i + 1] <= '6') ans = (ans + 2 * f(i + 2) % mod ) % mod;
                else ans = (ans + f(i + 2) % mod);
            }
        } else {
            ans += f(i + 1);
            if (s[i + 1] == '*') {
                if (s[i] == '1') ans = (ans + 9 * f(i + 2) % mod) % mod;
                if (s[i] == '2') ans = (ans + 6 * f(i + 2) % mod) % mod;
            } else {
                string sub = s.substr(i, 2);
                if (stoi(sub) <= 26) ans = (ans + f(i + 2) % mod) % mod;
            }
        }
        return dp[i] = ans % mod;
    }
};


// Tabulation
class Solution {

public:
    int numDecodings(string s) {
        const int M = 1000000007;
        int n = s.size();

        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        if (s[0] == '*') {
            dp[1] = 9;
        } else {
            if (s[0] == '0') {
                dp[1] = 0;
            } else {
                dp[1] = 1;
            }
        }

        for (int i = 1; i < n; i++) {
            char num = s[i];

            if (num == '*') {
                dp[i + 1] = (9LL * dp[i]) % M;

                if (s[i - 1] == '1') {
                    dp[i + 1] = (dp[i + 1] + 9LL * dp[i - 1]) % M;
                } else if (s[i - 1] == '2') {
                    dp[i + 1] = (dp[i + 1] + 6LL * dp[i - 1]) % M;
                } else if (s[i - 1] == '*') {
                    dp[i + 1] = (dp[i + 1] + 15LL * dp[i - 1]) % M;
                }
            } else {
                if (num != '0') {
                    dp[i + 1] = dp[i];
                }

                if (s[i - 1] == '1' || (s[i - 1] == '2' && num <= '6')) {
                    dp[i + 1] = (dp[i + 1] + dp[i - 1]) % M;
                } else if (s[i - 1] == '*') {
                    if (num <= '6') {
                        dp[i + 1] = (dp[i + 1] + 2LL * dp[i - 1]) % M;
                    } else {
                        dp[i + 1] = (dp[i + 1] + dp[i - 1]) % M;
                    }
                }
            }
        }

        return dp[n];
    }
};
