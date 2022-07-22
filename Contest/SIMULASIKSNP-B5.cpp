# include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
  int n;
  ll k;
  cin >> n >> k;
  
  ll a[n];
  for(int x=0;x<n;x++){
      cin >> a[x];
      a[x] -= k;
  }
  
  map<ll, int> mp;
  mp[0] = 1;
  
  ll ans = 0;
  ll sum = 0;
  for(int x=0;x<n;x++){
      sum += a[x];
      
      ans += mp[sum];
      mp[sum]++;
      
      if(x > 0) cout << " ";
      cout << ans;
  }
  cout << "\n";
  return 0;
}

