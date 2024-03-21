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

int upper(vector<long long> &arr, int x)
{
	int n = arr.size();
	int l = 0, h = n - 1;
	while (l <= h)
	{
		int m = (l + h) / 2;
		if (arr[m] <= x)
		{
			l = m + 1;
		}
		else
		{
			h = m - 1;
		}
	}
	return l;
}

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i)
		cin >> b[i];

	vector<long long> prea(n + 1, 0), preb(m + 1, 0);
	for (int i = 1; i <= n; ++i)
		prea[i] = prea[i - 1] + a[i - 1];
	for (int i = 1; i <= m; ++i)
		preb[i] = preb[i - 1] + b[i - 1];

	int ans = 0;
	for (int i = 0; i <= n; ++i)
	{
		if (prea[i] > k)
			break;
		int j = upper(preb, k - prea[i]) - 1;
		ans = max(ans, i + j);
	}

	cout << ans << endl;
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
