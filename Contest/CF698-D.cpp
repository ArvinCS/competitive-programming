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
	
	ll t;
	cin >> t;
	
	while(t--){
		ll n, m;
		cin >> n >> m;
		
		vector<ll> data;
		unordered_set<ll> exist;
		for(ll x=0;x<n;x++){
			ll tmp;
			cin >> tmp;
			
			if(!exist.count(tmp)){
				data.push_back(tmp);
				exist.insert(tmp);
			}
		}
		
		if(exist.count(m)){
			cout << "YES\n";
			continue;
		}
		
		ll gc = data[1]-data[0];
		for(int x=2;x<n;x++){
			gc = __gcd(gc, data[x]-data[0]);	
		}
		
		if((m-data[0])%gc == 0) cout << "YES\n";
		else cout << "NO\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

