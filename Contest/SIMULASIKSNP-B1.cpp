# include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
  int n;
  cin >> n;
  
  int table[n+1][n+1];
  fill(table[0], table[n+1], 0);
  
  table[0][0] = 1;
  for(int x=1;x<=n;x++){
      for(int y=0;y<=x+1;y++){
          if(x-y > 0){
              table[x][y] += table[x-1][y];
          }
          if(y >= x/2){
              table[x][y+1] += table[x-1][y];
          }
      }
  }
  
  ll ans = 0;
  for(int x=0;x<=n;x++){
      ans += table[n-1][x];
  }
  
  cout << ans << "\n";
  return 0;
}

