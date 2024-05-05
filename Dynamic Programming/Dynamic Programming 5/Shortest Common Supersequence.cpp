class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
    int n=a.size(),m=b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;++i){
        dp[i][0]=0;
    }
    for(int j=0;j<=m;++j){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string ans="";
    int i=n,j=m;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            ans+=a[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    i=0;
    int k=0,l=0;
    string s1="",s2="",res="";
    while(i<ans.size()){
        while(a[k]!=ans[i]){
            s1+=a[k];
            k++;
        }
        while(b[l]!=ans[i]){
            s2+=b[l];
            l++;
        }
        res+=s1;
        res+=s2;
        res+=ans[i];
        i++;
        k++;
        l++;
        s1="";
        s2="";
    }
    while(k<a.size()){
        res+=a[k];
        k++;
    }
    while(l<b.size()){
        res+=b[l];
        l++;
    }
    return res;
    }
};
