//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends



int pos(int mat[][1000],int t,int n){
    int ans=0;
    for(int i=0;i<n;++i){
        int m=n-1;
        while(m>=0 && mat[i][m]>t){
            m--;
        }
        ans+=(m+1);
    }
    return ans;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  int l=mat[0][0],h=mat[n-1][n-1];
  int ans=0;
  while(l<=h){
      int m=(l+h)/2;
      if(pos(mat,m,n)>=k){
          ans=m;
          h=m-1;
      }
      else{
          l=m+1;
      }
  }
  return ans;
}
