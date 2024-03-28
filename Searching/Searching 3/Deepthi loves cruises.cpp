#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define endl '\n'
typedef long long ll;
const int mod = 1e9 + 7;
#define MAX 1000

bool prime(int n){
	for(int i=2;i*i<=n;++i){
		if(n%i==0) return false;
	}
	return true;
}

void sieve(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime)); 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}







bool check(int num,int limit,const unordered_map<int,int>&mp){
    int cnt=0;
    for(auto &x:mp){
        if(x.second>=num){
            cnt++;
        }
    }
    if(cnt>=limit){
        return true;
    }
    else{
        return false;
    }
}

void solve()
{
	int a; cin>>a;
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    if(a>n){
        cout<<0<<endl;
        return;
    }
    int low=1,high=n/a;
    unordered_map<int,int> mp;
    for(int i=0;i<n;++i) mp[v[i]]++;
    while(low<=high){
        int mid=(low+high)/2; // lunch
        if(check(mid,a,mp)==true){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<high<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	t = 1;
	cin >> t;
	while (t--){
		solve();
	}
}
