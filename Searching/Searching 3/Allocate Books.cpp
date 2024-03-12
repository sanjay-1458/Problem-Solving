
int fun(vector<int>&arr,int pages){
    int cnt=1,sum=arr[0];
    for(int i=1;i<arr.size();++i){
        if(sum+arr[i]<=pages){
            sum+=arr[i];
        }
        else{
            cnt++;
            sum=arr[i];
        }
    }
    return cnt;
}

int findPages(vector<int>& arr, int n, int m) {
    int maxi=arr[0],sum=0;
    if(n<m) return -1;
    for(int i=0;i<n;++i){
        if(maxi<arr[i]){
            maxi=arr[i];
        }
        sum+=arr[i];
    }
    int low=maxi,high=sum,ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int cnt=fun(arr,mid);
        if(cnt>m){
            low=mid+1;
        }
        else if(cnt<m){
            high=mid-1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}
