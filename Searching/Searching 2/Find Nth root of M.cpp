//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
	public:
	int NthRoot(int n, int m)
	{
	    long long ans=-1, low=1,high=m;
	    while(low<=high){
	        long long int mid=(high+low)/2;
	        long long power=1;
	        for(int i=0;i<n;++i){
	            power=power*mid;
	            if(power>m) break;
	        }
	        if(power==m){
	            ans=mid;
	            break;
	        }
	        else if(power>m){
	            high=mid-1;
	        }
	        else{
	            low=mid+1;
	        }
	    }
	    return ans;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends
