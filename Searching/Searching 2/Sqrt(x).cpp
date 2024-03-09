class Solution {
public:
    int mySqrt(int x) {
        int l=1,h=x;
        while(l<=h){
            int m=l+(h-l)/2;
            if(m==x/m){
                return m;
            }
            else if(m<x/m){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return h;
    }
};
