//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool place(vector<int> &stalls,int k,int dist){
        int prev=0;
        int cnt=1;
        for(int i=1;i<stalls.size();++i){
            if(stalls[i]-stalls[prev]>=dist){
                cnt++;
                prev=i;
            }
            if(cnt>=k) return true;
        }
        return false;
    }
public:

    int solve(int n, int k, vector<int> &stalls) {
        // sort(stalls.begin(),stalls.end());
        // int maxi=stalls[n-1]-stalls[0],ans=0;
        // for(int i=1;i<=maxi;++i){
        //     int dist=i,prev=0, c=k;
        //     for(int j=0;j<n;++j){
        //         if(j==0){
        //             c--;
        //             prev=0;
        //         }
        //         else if(stalls[j]-stalls[prev]>=dist){
        //             c--;
        //             prev=j;
        //         }
        //         if(c==0) break;
        //     }
        //     if(c==0){
        //         ans=max(ans,dist);
        //     }
        //     else{
        //         break;
        //     }
        // }
        // return ans;
        sort(stalls.begin(),stalls.end());
        int low=0,high=stalls[n-1]-stalls[0];
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(place(stalls,k,mid)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
