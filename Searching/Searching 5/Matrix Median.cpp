int fun(vector<int>&R,int mid){
    int l=0,h=R.size()-1;
    while(l<=h){
        int m=(l+h)/2;
        if(R[m]<=mid){
            l=m+1;
        }
        else{
            h=m-1;
        }
    }
    return l;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int l=1,h=(int)1e9;
    int n=A.size(),m=A[0].size();
    while(l<=h){
        int mid=(h+l)/2;
        int lessmid=0;
        for(int i=0;i<n;++i){
            
            lessmid+=fun(A[i],mid);
        }
        if(lessmid<=(n*m)/2){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return l;
}
