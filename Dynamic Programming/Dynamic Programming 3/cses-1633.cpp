#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
#define read(v, n)              \
    for (int i = 0; i < n; ++i) \
        cin >> v[i];
const int mod=(int)1e9+7;
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
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = 0;
        for (int j = i - 1; j >= max(i - 6, 0); --j)
        {
            dp[i] = (dp[j] + dp[i]) % mod;
        }
    }
    cout << dp[n];
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
