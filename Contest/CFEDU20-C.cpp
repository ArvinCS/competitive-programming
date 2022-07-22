#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	ll n, k;
	cin >> n >> k;
	
	if(k == 1){
		cout << n << "\n";
		return 0;
	}
	
	if(k > 141421){
		cout << "-1\n";
		return 0;
	}
	
	ll mn = k*(k+1)/2;
	if(mn > n){
		cout << "-1\n";
		return 0;
	}
	
	ll best = -1;
	for(ll x=2;x*x<=n;x++){
		if(n%x == 0){
			if(best > x) continue;
			
			ll cnt = n/x;
			if(cnt >= k && x*mn <= n){
				best = x;
			}
			
			if(n/x != x && n/x > best && x >= k && (n/x)*mn <= n){
				best = n/x;
			}
		}
	}
	
	if(best == -1){
		for(ll x=0;x<k-1;x++){
			cout << (x+1) << " ";
		}
		cout << n-(k-1)*k/2 << "\n";
		return 0;
	}
	
	for(ll x=0;x<k-1;x++){
		cout << best*(x+1) << " ";
	}
	cout << best*((n/best)-(k-1)*k/2) << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

