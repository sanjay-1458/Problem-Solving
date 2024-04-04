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
#define pb push_back

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

bool prime(int n)
{
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void sieve(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////


void solve()
{
    vector<int> pre={20, 10, 11, 13, 12};
    int n=pre.size();
    vector<int> maxi(n),mini(n);
    maxi[n-1]=pre[n-1];
    for(int i=n-2;i>=0;--i){
        maxi[i]=max(maxi[i+1],pre[i]);
    }
    mini[n-1]=pre[n-1];
    for(int i=n-2;i>=0;--i){
        mini[i]=min(mini[i+1],pre[i]);
    }
    bool ans=true;
    for(int i=0;i<n-1;++i){
        if(pre[i]>maxi[i+1] || pre[i]<mini[i+1]){
            continue;
        }
        else{
            ans=false;
            break;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
