# include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
  int n, c;
  ll p;
  cin >> n >> c >> p;
  
  pair<int, ll> w[n];
  for(int x=0;x<n;x++){
      cin >> w[x].first >> w[x].second;
  }
  
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  int ans = 0;
  ll sum = 0;
  for(int x=0;x<n;x++){
      ans = max(ans, w[x].first-(x > 0 ? w[x-1].first : 0));
      
      sum += w[x].second;
      pq.push(w[x].second);
      
      while(pq.size() > c){
          sum -= pq.top();
          pq.pop();
      }
      
      if(sum >= p){
          break;
      }
  }
  
  cout << ans << "\n";
  return 0;
}

