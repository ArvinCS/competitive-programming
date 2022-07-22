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
	
	ll n, k;
	cin >> n >> k;
	
	if((k*(k+1))/2 > n){
		cout << "NO\n";
		return 0;
	}
	
	bool possible = true;
	ll ans[k];
	
	for(int x=0;x<k;x++){
		ans[x] = x+1;
		n -= (x+1);
	}
	
	if(n > 0){
		ll tmp = n/k, rem = n%k;
		for(int x=0;x<k;x++){
			ans[x] += tmp;
			n -= tmp;
		}
		
		int idx = k-1;
		for(int x=k-1;x>0;x--){
			if(rem <= 0) break;
			int mn = min(2*ans[x-1]-ans[x], rem);
			ans[x] += mn;
			rem -= mn;
			n -= mn;
		}
		
		if(rem > 0 && n > 1){
			int mn = min(ans[1] - ans[0] - 1, rem);
			ans[0] += mn;
			rem -= mn;
			n -= mn;
		}
	}
	
//	cout << n << "\n";
	if(n > 0) possible = false;
	for(int x=0;x<k-1;x++){
		if(ans[x] > ans[x+1] || ans[x+1] > 2*ans[x]){
			possible = false;
			break;
		}
	}
	
	if(possible){
		cout << "YES\n";
		for(int x=0;x<k;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	} else {
		cout << "NO\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

