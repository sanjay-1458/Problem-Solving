class Solution {
public:
    int equalSubstring(string s, string t, int cost) {
        int n=s.size();
        int len=0,sum=0,i=0,j=0;
        while(i<n){
            sum+=abs(s[i]-t[i]);
            if(sum<=cost){
                len=max(len,i-j+1);
            }
            else{
                while(sum>cost){
                    sum-=abs(s[j]-t[j]);
                    j++;
                }
            }
            i++;
        }
        return len;
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////
