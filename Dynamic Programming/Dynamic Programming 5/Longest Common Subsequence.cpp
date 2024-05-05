class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
     	int ind1=s.size()-1;
        int ind2=t.size()-1;
        if(s.size()==0 || t.size()==0) return 0;
        vector<vector<int>> dp(ind1+1,vector<int>(ind2+1,0));
        for(int i=0;i<=ind1;++i){
            for(int j=0;j<=ind2;++j){
                if(i==0 && j==0){
                    if(s[i]==t[j]){
                        dp[i][j]=1;
                    }
                }
                else if(i==0 && j!=0){
                    for(int l=0;l<=j;++l){
                        if(s[i]==t[l]){
                            dp[i][j]= 1;
                        }
                    }
                }
                else if(j==0 && i!=0){
                    for(int l=0;l<=i;++l){
                        if(s[l]==t[j]){
                            dp[i][j]=1;
                        }
                    }
                }
                else if(s[i]==t[j]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    int first=dp[i-1][j];
                    int second=dp[i][j-1];
                    dp[i][j]=max(first,second);
                }
            }
        }
        return dp[ind1][ind2];   
    }
};
