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
class Solution {
    bool check(int len,int val,string&s,string&t){
        int i=0,j=0,n=s.size();
        int sum=0;
        while(j<n){
            sum+=abs(s[j]-t[j]);
            if(j-i+1<len){
                j++;
            }
            else{
                if(sum<=val){
                    return true;
                }
                sum-=abs(s[i]-t[i]);
                i++;
                j++;
            }
        }
        return false;
    }
public:
    int equalSubstring(string s, string t, int mx) {
        int n=s.size();
        int low=0,high=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,mx,s,t)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high==-1?0:high;
    }
};
