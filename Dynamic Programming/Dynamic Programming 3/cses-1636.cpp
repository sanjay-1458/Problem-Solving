#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define endl '\n'
 
const int mod = (int)1e9 + 7;
 
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<int> coins(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> coins[i];
    
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0)); // Using 2D vector
    
    for (ll i = 1; i <= n; ++i)
    {
        for (ll j = 0; j <= k; ++j)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                int a = 0, b = 0;
                if (i != 1)
                    a = dp[i - 1][j];
                if (coins[i] <= j)
                    b = dp[i][j - coins[i]];
                dp[i][j] = (a + b) % mod;
            }
        }
    }
    std::cout << dp[n][k] << endl;
}
 
int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
