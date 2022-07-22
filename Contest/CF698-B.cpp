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

bool digit(ll n, int p){
	bool ans = false;
	while(n > 0){
		if(n % 10 == p){
			ans = true;
			break;
		}
		n /= 10;
	}
	return ans;	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		ll data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		for(int x=0;x<n;x++){
			bool possible = false;
			for(ll y=0;y*m<=data[x];y++){
				if(digit(data[x]-(y*m), m)){
					possible = true;
					break;
				}
			}
			if(possible) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

