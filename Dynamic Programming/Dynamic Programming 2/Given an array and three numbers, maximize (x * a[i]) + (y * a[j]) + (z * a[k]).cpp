
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
#define read(v, n)              \
    for (int i = 0; i < n; ++i) \
        cin >> v[i];
const int mod = (int)1e9 + 7;
class Compare
{
public:
    bool operator()(int a, int b)
    {
        return a < b;
    }
};

int maximizeExpr(vector<int>a, int n, int x, int y, int z) { 
	int L[n]; 
	L[0] = x * a[0]; 
	for (int i = 1; i < n; i++) 
		L[i] = max(L[i - 1], x * a[i]); 

	int R[n]; 
	R[n-1] = z * a[n-1]; 
	for (int i = n - 2; i >= 0; i--) 
		R[i] = max(R[i + 1], z * a[i]); 

	int ans = INT_MIN; 
	for (int i = 0; i < n; i++) 
		ans = max(ans, L[i] + y * a[i] + R[i]); 

	return ans; 
} 

void solve()
{
    int n,x,y,z; cin>>n>>x>>y>>z;
    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];
    cout<<maximizeExpr(arr,n,x,y,z)<<endl;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
