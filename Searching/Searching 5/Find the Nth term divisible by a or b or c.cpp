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

int gcd(int a, int b)
{
    if (a == 0) return b;
    return gcd(b % a, a);
}

int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}

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
            for (int i = p * p; i <= n; i += p){
                prime[i] = false;
            }
        }
    }
}




int check(int a,int b,int c,int n){
    int val=n/a+n/b+n/c-n/lcm(a,b)-n/lcm(b,c)-n/lcm(a,c)+n/lcm(a,lcm(b,c));
    return val;
}

void solve()
{
	int a,b,c,n;
    cin>>a>>b>>c>>n;
    int low=1,high=INT_MAX;
    while(low<=high){
        int mid=low+(high-low)/2; // num
        if(check(a,b,c,mid)<n){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<low<<endl;
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
