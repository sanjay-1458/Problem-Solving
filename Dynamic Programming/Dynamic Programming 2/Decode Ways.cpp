// Recursion
class Solution {
    int fun(int i,string &s){
        int n=s.size();
        if(s[i]=='0'){
            return 0;
        }
        if(i>=n){
            return 1;
        }
        int pick1=0,pick2=0;
        if(i+1<n){
            string curr="";
            curr+=s[i];
            curr+=s[i+1];
            int val=stoi(curr);
            if(val>=10 && val<=26){
                pick2=fun(i+2,s);
            }
        }
        pick1=fun(i+1,s);
        return pick1+pick2;
    }
public:
    int numDecodings(string s) {
        int n=s.size();
        return fun(0,s);
    }
};

// Memoization
class Solution {
    int fun(int i,string &s,vector<int> &dp){
        int n=s.size();
        if(s[i]=='0'){
            return 0;
        }
        if(i>=n){
            return 1;
        }
        if(dp[i]!=-1) return dp[i];
        int pick1=0,pick2=0;
        if(i+1<n){
            string curr="";
            curr+=s[i];
            curr+=s[i+1];
            int val=stoi(curr);
            if(val>=10 && val<=26){
                pick2=fun(i+2,s,dp);
            }
        }
        pick1=fun(i+1,s,dp);
        return dp[i]=pick1+pick2;
    }
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return fun(0,s,dp);
    }
};

// Tabulation
class Solution {

public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        for(int i=n;i>=0;--i){
            if(i==n){
                dp[i]=1;
                continue;
            }
            if(s[i]=='0'){
                dp[i]=0;
            }
            else{
                int pick1=0,pick2=0;
                if(i+1<n){
                    string curr="";
                    curr+=s[i];
                    curr+=s[i+1];
                    int val=stoi(curr);
                    if(val>=10 && val<=26){
                        pick2=dp[i+2];
                    }
                }
                pick1=dp[i+1];
                dp[i]=pick1+pick2;
            }
        }
        return dp[0];
    }
};
