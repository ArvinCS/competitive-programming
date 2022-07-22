# include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

int cnt[maxN];

int main(){
  int n;
  cin >> n;
  
  fill(cnt, cnt+maxN, 0);
  
  int a[n];
  for(int x=0;x<n;x++){
      cin >> a[x];
  }
  
  ll ans = 1, sum = 0;
  for(int x=0;x<n;x++){
      ans += sum - cnt[a[x]];
      sum++;
      cnt[a[x]]++;
  }
  
  cout << ans << "\n";
  return 0;
}

