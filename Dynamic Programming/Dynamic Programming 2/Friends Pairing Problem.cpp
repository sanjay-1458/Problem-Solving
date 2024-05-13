// Recursion
const int MOD=(int)1e9+7;
    int fun(int i){
        if (i <= 2) return i;
        return (fun(i - 1) + (i - 1) * fun(i - 2)) % MOD;
    }
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        return fun(n);
    }
// Memoization
long long  fun(int i,vector<long long> &dp){
        
        if(i<=2) return i;
        if(dp[i]!=-1)   return dp[i];
        long long  ans = fun(i-1,dp)%MOD + ((i-1)*((fun(i-2,dp))%MOD))%MOD;
        
        return dp[i] = ans%MOD; 
    
    }
    int countFriendsPairings(int n) 
    { 
        vector<long long> dp(n+1,-1);
        return fun(n,dp);
    }
// Tabultaion
public:
    const int MOD = (int)1e9 + 7;

    int countFriendsPairings(int n) {
        if (n <= 2) return n;
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            long long ans = (dp[i - 1] % MOD + ((i - 1) * dp[i - 2] % MOD) % MOD) ;
            dp[i] = ans%MOD;
        }
        return dp[n];
    }

// space Optimization
int countFriendsPairings(int n) {
        if (n <= 2) return n;
        vector<long long> dp(n + 1, 0);
        long long prev2 = 1;
        long long int prev1 = 2;
        for (int i = 3; i <= n; ++i) {
            long long ans = (prev1 % MOD + ((i - 1) * prev2 % MOD) % MOD) ;
             long long int curr = ans%MOD;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
