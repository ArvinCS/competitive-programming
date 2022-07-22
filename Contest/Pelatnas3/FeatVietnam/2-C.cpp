#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const int bit = 14;
const int mx = (1 << bit);

ll powmod(ll x, ll y){
	ll ans = 1;
	
	x %= mod;
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x * x) % mod;
	}
	return ans;
}

void chadd(ll &a, ll b){
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int q;
	cin >> q;
	
	ll cnt[mx];
	fill(cnt, cnt+mx, 0);
	
	ll table[mx];
	vector<int> v;
	
	while(q--){
		string s;
		cin >> s;
		
		if(s == "XOR"){
			assert(false);
//			int val;
//			cin >> val;
//			
//			for(int x=0;x<mx;x++){
//				table[cur+1][x] = 0;
//			}
//			for(int x=0;x<mx;x++){
//				chadd(table[cur+1][x], table[cur][x]);
//				chadd(table[cur+1][x^val], table[cur][x]);
//			}
//			cur++;
		} else if(s == "AND"){
			assert(false);
//			int val;
//			cin >> val;
//			
//			for(int x=0;x<mx;x++){
//				table[cur+1][x] = 0;
//			}
//			for(int x=0;x<mx;x++){
//				chadd(table[cur+1][x], table[cur][x]);
//				chadd(table[cur+1][x&val], table[cur][x]);
//			}
//			cur++;
		} else if(s == "OR"){
			int val;
			cin >> val;
			
			cnt[val]++;
			v.push_back(val);
		} else if(s == "REMOVE"){
			cnt[v.back()]--;
			v.pop_back();
		} else if(s == "QUERY"){
			int val;
			cin >> val;
			
			fill(table, table+mx, 0);
			
			for(int x=0;x<mx;x++){
				table[x] = (powmod(2, cnt[x])-1+mod)%mod;
			}
			for(int x=0;x<bit;x++){
				for(int y=0;y<mx;y++){
					if(y&(1 << x)){
						table[y] *= (table[y^(1 << x)]+1);
						table[y] %= mod;
					}
				}
			}
			
			ll ans = table[val];
			for(int x=0;x<bit;x++){
				if((val&x) == x){
					if(__builtin_popcount(x) % 2 == val % 2) chadd(ans, table[x]);
					else chadd(ans, -table[x]);
				}
			}
			
			cout << ans << "\n";
		}
	}
	
	return 0;	
}
