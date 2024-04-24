class Solution {
    bool check(vector<int>& hs, vector<int>& ht,long long radius){
        long long n=hs.size(),m=ht.size();
        long long i=0,j=0;
        while(i<n && j<m){
            long long mini=ht[j]-radius;
            long long maxi=ht[j]+radius;
            if(hs[i]>=mini && hs[i]<=maxi){
                i++;
            }
            else{
                j++;
            }
        }
        return i==n;
    }
public:
    int findRadius(vector<int>& hs, vector<int>& ht) {
        sort(hs.begin(),hs.end());
        sort(ht.begin(),ht.end());
        long long int low=0,high=2e10;
        while(low<=high){
            long long mid=(low+high)/2; // radius
            if(check(hs,ht,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
