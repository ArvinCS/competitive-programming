# include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll fac[5005];

ll powmod(ll x, ll y){
    ll ans = 1;
    
    while(y>0){
        if(y&1) ans = (ans*x) % mod;
        
        y >>= 1;
        x = (x*x) % mod;
    }
    return ans;
}

int main(){
  fac[0] = fac[1] = 1;
  for(ll x=2;x<5005;x++){
      fac[x] = (x*fac[x-1]) % mod;
  }
  
  int n;
  cin >> n;
  
  ll table[n][n+1];
  fill(table[0], table[n], 0);
  
  table[0][1] = 1;
  for(int x=0;x<n-1;x++){
      for(int y=1;y<=x+1;y++){
          if(y > (x+1)/2){
              table[x+1][y] += table[x][y];
              table[x+1][y] %= mod;
          }
          if(y >= (x+2)/2){
              table[x+1][y+1] += table[x][y];
              table[x+1][y+1] %= mod;
          }
      }
  }
  
  ll ans = 0;
  for(int x=0;x<=n;x++){
      ans += table[n-1][x];
      ans %= mod;
  }
  
  if(n%2 == 0){
    ans = (ans - table[n-1][n/2] + mod) % mod;
   	ans += (fac[n] * powmod(fac[n/2], mod-2) % mod * powmod(fac[n/2], mod-2) % mod);
   	ans %= mod;
  }
  return 0;
}

