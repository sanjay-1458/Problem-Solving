
// LIS dp
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](vector<int>a,vector<int>b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            else{
                return a[0]<b[0];
            }
        });
        int n=envelopes.size();
        vector<int> dp(n,1);
        int ans=1;
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
                ans=max(ans,dp[i]);
            }
        }
        return ans;
    }
};

class Solution {
    int lower(int k,vector<int>&nums){
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](vector<int>a,vector<int>b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            else{
                return a[0]<b[0];
            }
        });
        int n=envelopes.size();
        vector<int> temp;
        for(int i=0;i<n;++i){
            int el=envelopes[i][1];
            int ind=lower(el,temp);
            if(ind>=(int)temp.size()) temp.push_back(el);
            else temp[ind]=el;
        }
        return (int)temp.size();
    }
};
