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

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x * x) % mod;
	}
	return ans;
}

int convert(string s){
	if(s == "white" || s == "yellow") return 0;
	else if(s == "green" || s == "blue") return 1;
	else if(s == "red" || s == "orange") return 2;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int k;
	cin >> k;
	
	int n;
	cin >> n;
	
	set<ll> v[k+1];
	map<ll, ll> mp[3];
	map<ll, int> p;
	set<ll> st;
	
	for(int x=0;x<n;x++){
		ll val;
		string s;
		
		cin >> val >> s;
		
		st.insert(val);
		p[val] = convert(s);
		for(int i=0;i<k;i++){
			ll bit = (1ll << i);
			ll bit2 = 2*bit-1;
			if(bit <= val && val <= bit2){
				mp[p[val]][val]++;
				v[i].insert(val);
			}
		}
	}
	
	for(int i=k-1;i>=0;i--){
		ll tmp = powmod(4, pow(2, k-i-1)-1);
		for(auto val : v[i]){
			if(!st.count(val)){
				for(int x=0;x<3;x++){
					if(mp[x].find(val) == mp[x].end()){
						mp[x][val] = 2;
					}
				}
			}
			
			if(i > 0) v[i-1].insert(val/2);
			if(i < k-1){
				if(!v[i+1].count(val*2)){
					mp[0][val] *= tmp;	
					mp[0][val] %= mod;
					
					mp[1][val] *= tmp;
					mp[1][val] %= mod;
					
					mp[2][val] *= tmp;		
					mp[2][val] %= mod;
				}
				if(!v[i+1].count(val*2+1)){
					mp[0][val] *= tmp;	
					mp[0][val] %= mod;
					
					mp[1][val] *= tmp;
					mp[1][val] %= mod;
					
					mp[2][val] *= tmp;		
					mp[2][val] %= mod;
				}
				
				if(p.find(val) != p.end()){
					int y = (p[val]-1+3)%3, z = (p[val]+1)%3;
					
					if(v[i+1].count(val*2)) mp[p[val]][val] *= (mp[y][val*2] + mp[z][val*2]) % mod;
					mp[p[val]][val] %= mod;
					if(v[i+1].count(val*2+1)) mp[p[val]][val] *= (mp[y][val*2+1] + mp[z][val*2+1]) % mod;
					mp[p[val]][val] %= mod;
					continue;
				}
				
				for(int x=0;x<3;x++){
					int y = (x-1+3)%3, z = (x+1)%3;
					
					if(v[i+1].count(val*2)) mp[x][val] *= (mp[y][val*2] + mp[z][val*2]) % mod;
					mp[x][val] %= mod;
					if(v[i+1].count(val*2+1)) mp[x][val] *= (mp[y][val*2+1] + mp[z][val*2+1]) % mod;
					mp[x][val] %= mod;
				}
			}
		}
	}
	
	ll ans = 0;
	for(int x=0;x<3;x++){
		ans += mp[x][1];
		ans %= mod;
	}
	
	cout << ans % mod << "\n";
    return 0;
}

