// Memoization

class Solution {
    long long maximumNonAdjacentSum(vector<long long> &arr){

    long long n=arr.size();
    if(n==0){
        return 0;
    }
    if(n==1){
        return arr[0];
    }
    vector<long long> dp(n+1,0);
    long long prev2=0;
    long long prev1=arr[0];
    for(long long i=2;i<=n;++i){
        long long exclude=prev1;
        long long include=arr[i-1]+prev2;
        long long curr=max(include,exclude);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;;
}
public:
    int rob(vector<int>& arr) {
           int n=arr.size();
    vector<long long> temp1,temp2;
    if(n==1){
        return arr[0];
    }
    for(int i=0;i<n;++i){
        if(i!=0)
        temp1.push_back(arr[i]);
        if(i!=n-1)
        temp2.push_back(arr[i]);
    } 
    long long ans1=maximumNonAdjacentSum(temp1);
    long long ans2=maximumNonAdjacentSum(temp2);
    return max(ans1,ans2);
    }
};


// Tabulation
class Solution {
    int fun1(vector<int>&nums){
        int n=nums.size();
        int prev1=nums[0];
        int prev2=0;
        for(int i=1;i<n-1;++i){
            int pick=0,notpick=0;
            notpick=prev1;
            pick=nums[i];
            if(i>1){
                pick+=prev2;
            }
            int curr=max(pick,notpick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int fun2(vector<int>&nums){
        int n=nums.size();
        if(n<=1) return 0;
        int prev1=nums[1];
        int prev2=0;
        for(int i=2;i<n;++i){
            int pick=0,notpick=0;
            notpick=prev1;
            pick=nums[i];
            if(i>2){
                pick+=prev2;
            }
            int curr=max(pick,notpick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        return max(fun1(nums),fun2(nums));
    }
};
