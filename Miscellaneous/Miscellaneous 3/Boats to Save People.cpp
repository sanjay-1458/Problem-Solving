class Solution {
public:
    int numRescueBoats(vector<int>& p, int l) {
        sort(p.begin(),p.end());
        int ans=0;
        int i=0,j=p.size()-1;
        while(i<=j){
            if(p[i]+p[j]>l){
                ans++;
                j--;
            }
            else{
                i++;
                j--;
                ans++;
            }
        }
        return ans;
    }
};
