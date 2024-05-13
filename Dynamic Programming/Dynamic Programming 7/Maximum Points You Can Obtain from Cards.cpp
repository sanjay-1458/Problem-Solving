// Resursion
class Solution {
public:
    int fun(vector<int>& cardPoints, int l, int h, int k){
        if (k==0) return 0;
        return max(cardPoints[l]+fun(cardPoints, l+1, h, k-1), cardPoints[h]+fun(cardPoints, l, h-1, k-1));
    }

    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        if (k>=n){
            int sum=0;
            for(auto &e : cardPoints) sum+= e;
            return sum;
        }
        else{
            return fun(cardPoints, 0, n-1, k);
        }
    }
};

// tabulation
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxScore = 0;
        vector<int> front(k + 1), rear(k + 1);
        front[0] = rear[0] = 0;

        for (int i = 0; i < k; i++) {
            front[i + 1] = front[i] + cardPoints[i];
            rear[i + 1] = rear[i] + cardPoints[n - 1 - i];
        }

        for (int i = 0; i <= k; i++) {
            int currentScore = front[i] + rear[k - i];
            maxScore = max(maxScore, currentScore);
        }
        return maxScore;
    }
};

// Space Optimization
class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int n=cardPoints.length;
        int sum1=0,sum2=0;
        int front=0,back=0;
        for(int i=0;i<k;++i){
            front+=cardPoints[i];
        }
        if(k==n){
            return front;
        }
        for(int i=n-1;i>=n-k;--i){
            back+=cardPoints[i];
        }
        int res;
        sum1=front;
        res=sum1;
        int i=k-1,j=n-1;
        for(;i>=0 && j>=n-k+1;i--,j--){
            sum1-=cardPoints[i];
            sum2+=cardPoints[j];
            res=res>(sum1+sum2)?res:(sum1+sum2);
        }
        res=res>back?res:back;
        return res;
    }
}

// Optimized
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
