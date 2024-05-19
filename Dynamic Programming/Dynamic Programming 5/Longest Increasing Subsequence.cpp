// Recursion
// class Solution {
//     int lis(int i,int p,vector<int>&nums){
//         if(i==-1) return 0;
//         int notPick=lis(i-1,p,nums);
//         int pick=0;
//         if(p==-1 || nums[i]<nums[p]){
//             pick=1+lis(i-1,i,nums);
//         }
//         return max(pick,notPick);
//     }
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         return lis(n-1,-1,nums);
//     }
// };

// Memoization
// class Solution {
//     int lis(int i,int p,vector<int>&nums,vector<vector<int>> &dp){
//         if(i==0) return 0;
//         if(dp[i][p]!=-1){
//             return dp[i][p];
//         }
//         int pick=0;
//         int notPick=lis(i-1,p,nums,dp);
//         if(p==0 || nums[i-1]<nums[p-1]){
//             pick=1+lis(i-1,i,nums,dp);
//         }
//         return dp[i][p]=max(pick,notPick);
//     }
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
//         int ans=lis(n,0,nums,dp);
//         return ans;
//     }
// };

// Memoization 2
// class Solution {
//     int lis(int i,int j,vector<int>&nums,vector<vector<int>> &dp){ // lis starting from i to end, where previous is at j
//         int n=nums.size();
//         if(i==n){
//             return 0;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         int pick=0;
//         int notPick=lis(i+1,j,nums,dp);
//         if(j==0 || nums[i]>nums[j-1]){
//             pick=1+lis(i+1,i+1,nums,dp);
//         }
//         return dp[i][j]=max(pick,notPick);
//     }
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>> dp(n,vector<int>(n+1,-1));
//         return lis(0,0,nums,dp);
//     }
// };


// Tabulation
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>> dp(n+1,vector<int>(n+1,0));
//         for(int i=n-1;i>=0;--i){
//             for(int j=i;j>=0;--j){
//                 int pick=0;
//                 int notPick=dp[i+1][j];
//                 if(j==0 || nums[i]>nums[j-1]){
//                     pick=1+dp[i+1][i+1];
//                 }
//                 dp[i][j]=max(pick,notPick);
//             }
//         }
//         return dp[0][0];
//     }
// };


// Space Optimization
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> next(n+1,0);
//         for(int i=n-1;i>=0;--i){
//             vector<int> curr(n+1,0);
//             for(int j=i;j>=0;--j){
//                 int pick=0;
//                 int notPick=next[j];
//                 if(j==0 || nums[i]>nums[j-1]){
//                     pick=1+next[i+1];
//                 }
//                 curr[j]=max(pick,notPick);
//             }
//             next=curr;
//         }
//         return next[0];
//     }
// };

// Space Optimization 2
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n,1); // let dp[i] denotes the maximum length lis ending at index i
//         for(int i=0;i<n;++i){
//             for(int j=0;j<i;++j){
//                 if(nums[i]>nums[j]){
//                     dp[i]=max(dp[i],1+dp[j]);
//                 }
//             }
//         }
//         int ans=0;
//         for(int i=0;i<n;++i){
//             ans=max(ans,dp[i]);
//         }
//         return ans;
//     }
// };


// LIS Traceback
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n,1);
//         vector<int> parent(n);
//         for(int i=0;i<n;++i){
//             parent[i]=i;
//         }
//         for(int i=0;i<n;++i){
//             for(int j=0;j<i;++j){
//                 if(nums[i]>nums[j]){
//                     dp[i]=max(dp[i],dp[j]+1);
//                     parent[i]=j;
//                 }
//             }
//         }
//         int maxi=1,ind=0;
//         for(int i=0;i<n;++i){
//             if(dp[i]>maxi){
//                 maxi=dp[i];
//                 ind=i;
//             }
//         }
//         vector<int> ans;
//         while(ind!=parent[ind]){
//             ans.push_back(nums[ind]);
//             ind=parent[ind];
//         }
//         ans.push_back(parent[ind]);
//         for(auto x:ans){
//             cout<<x<<" ";
//         }
//         return maxi;
//     }
// };

// Binary Search
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
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;++i){
            if(temp.back()<nums[i]){
                temp.push_back(nums[i]);
            }
            else{
                int pos=lower(nums[i],temp);
                temp[pos]=nums[i];
            }
        }
        return (int)temp.size();
    }
};
