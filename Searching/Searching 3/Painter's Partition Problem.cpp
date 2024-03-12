int fun(vector<int>&arr,int sub){
    long long sum=arr[0],cnt=1;
    for(int i=1;i<arr.size();++i){
        if(arr[i]+sum<=sub){
            sum+=arr[i];
            
        }
        else{
            sum=arr[i];
            cnt++;
        }
    }
    return cnt;
}

int findLargestMinDistance(vector<int> &nums, int k)
{
    long long int maxi=nums[0],sum=0;
    for(int i=0;i<nums.size();++i){
        if(nums[i]>maxi){
            maxi=nums[i];
        }
        sum+=nums[i];
    }
    int low=maxi,high=sum;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(fun(nums,mid)>k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
    
}
