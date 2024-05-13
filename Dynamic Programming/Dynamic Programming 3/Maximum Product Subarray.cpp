// Optimized
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int ans=INT_MIN,curr=1,n=arr.size();
        for(int i=0;i<n;++i){
            curr=curr*arr[i];
            ans=max(ans,curr);
            if(curr==0){
                curr=1;
            }
        }
        curr=1;
        for(int i=n-1;i>=0;--i){
            curr=curr*arr[i];
            ans=max(curr,ans);
            if(curr==0){
                curr=1;
            }
        }
        return ans;
    }
};


// Tabulation
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n , vector<int>( 2, nums[0]));
        int ans=nums[0];
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0]*nums[i]  , max( dp[i-1][1]*nums[i]  , nums[i] ));
            dp[i][1]=min( dp[i-1][0]*nums[i] , min( dp[i-1][1]*nums[i] , nums[i] ));
            ans = max(ans , max(dp[i][1] , dp[i][0]));
        }
        return ans; 
    }
};
