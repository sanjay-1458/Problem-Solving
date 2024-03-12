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
vector<vector<int>> ans;


bool check(int size,vector<int>&v,int s){
  int i=0,j=0,n=v.size();
  int sum=0;
  while(j<n){
    sum+=v[j];
    if(j-i+1<size){
      j++;
    }
    else{
      if(sum>s){
        return false;
      }
      sum-=v[i];
      i++;
      j++;
    }
  }
  return true;
}

void solve()
{
  int n; cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;++i) cin>>v[i];
  int s; cin>>s;
  int low=1,high=n-1;
  while(low<=high){
    int mid=(low+high)/2;
    if(check(mid,v,s)){
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
  // cin >> t;
  while (t--)
  {
    solve();
  }
}
