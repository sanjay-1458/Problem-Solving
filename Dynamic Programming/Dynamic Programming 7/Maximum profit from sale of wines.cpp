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

#define N 1000

int fun(vector<int> &price, int begin, int end, int n, vector<vector<int>> &dp, vector<vector<int>> &sell)
{
    if (dp[begin][end] != -1)
        return dp[begin][end];

    int year = n - (end - begin);

    if (begin == end)
        return year * price[begin];

    int x = price[begin] * year + fun(price, begin + 1, end, n, dp, sell);
    int y = price[end] * year + fun(price, begin, end - 1, n, dp, sell);

    int ans = max(x, y);
    dp[begin][end] = ans;

    if (x >= y)
        sell[begin][end] = 0;
    else
        sell[begin][end] = 1;

    return ans;
}

int maxProfit(vector<int> &profit, int n)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    vector<vector<int>> sell(N, vector<int>(N, 0));

    int ans = fun(profit, 0, n - 1, n, dp, sell);

    int i = 0, j = n - 1;

    while (i <= j)
    {
        if (sell[i][j] == 0)
        {
            cout << "beg ";
            i++;
        }
        else
        {
            cout << "end ";
            j--;
        }
    }

    cout << endl;

    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> profit(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> profit[i];
    }
    maxProfit(profit, n);
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
