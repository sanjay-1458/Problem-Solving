#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define vi vector<int>
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
 
void solve()
{
    int n, k;
    cin >> n >> k;
    vi coins(n);
    read(coins,n);
    vi dp(k+1);
    dp[0]=0;
    for(int i=1;i<=k;++i){
        dp[i]=INT_MAX;
        for(auto c:coins){
            if(i-c>=0 && dp[i-c]!=INT_MAX) dp[i]=min(dp[i],dp[i-c]+1);
        }
    }
    if(dp[k]==INT_MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<dp[k]<<endl;
    }
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
