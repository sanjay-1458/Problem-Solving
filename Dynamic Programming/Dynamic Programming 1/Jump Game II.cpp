// Recursion
class Solution {
   long long jump(vector<int> nums , long long curr, long long dest)
    {       
        if(curr>=dest) return 0; 
        long long ans=INT_MAX;
        for(int i=1;i<=nums[curr];++i)
        {
            ans=min(ans,1+jump(nums,curr+i,dest));  
        } 
        return ans;  
    }
public:
    int jump(vector<int>& nums) { 
        return jump(nums,0,nums.size()-1);
    }
};


// Memoization
class Solution {
   long long jump(vector<int> nums , long long curr,vector<int>& dp)
    {       
        int n=nums.size();
        if(curr>=n-1) return 0; 
        if(dp[curr]!=-1) return dp[curr];
        long long ans=INT_MAX;
        for(int i=1;i<=nums[curr];++i)
        {
            ans=min(ans,1+jump(nums,curr+i,dp));  
        } 
        return dp[curr]=ans;  
    }
public:
    int jump(vector<int>& nums) { 
        int n=nums.size();
        vector<int> dp(n,-1);
        return jump(nums,0,dp);
    }
};

// Tabulation
class Solution {

public:
    int jump(vector<int>& nums) { 
        int n=nums.size();
        vector<int> dp(n);
        for(int i=n-2;i>=0;--i){
            long long ans=INT_MAX;
            for(int j=1;j<=nums[i];++j)
            {   if(i+j<n)
                ans=min(ans,(long long )1+dp[i+j]);  
            } 
            dp[i]=ans;  
        }
        return dp[0];
        // return jump(nums,0,dp);
    }
};

// Greedy
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int i=0,mex=0,curr_jump=0;
        int jumps=0;

        while(i<n-1){
            mex = max(mex,i+nums[i]);

            if(i == curr_jump){
                curr_jump = mex;
                jumps++;
            }
            i++;
        }

        return jumps;
    }
};
