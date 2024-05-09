class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        long long ans=0,n=nums.size();
        long long sum1=0,sum2=0;
        for(int i=0;i<k;++i){
            sum1+=nums[i];
        }
        ans=max(ans,sum1);
        int i=k-1,j=n-1;
        while(i>=0){
            sum1-=nums[i];
            sum2+=nums[j];
            ans=max(ans,sum1+sum2);
            i--;
            j--;
        }
        return ans;
    }
};
