#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxLN = 1e4 + 5;
const int maxM = 10;
const ll mod = 998244353;

string s;
int m, c[maxM], must = 0;
pair<ll, ll> table[maxLN][(1 << maxM)][2];

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

pair<ll, ll> solve(int i, int state, bool less){
	if(i >= s.length()){
		return make_pair(0, (state&must) == must);
	}
	
	if(table[i][state][less].first != -1) return table[i][state][less];
	
	ll ans = 0, cnt = 0, pw = powmod(10ll, s.length()-i-1);
	for(int x=0;x<=(less ? 9 : (s[i] - '0'));x++){
		pair<ll, ll> p = solve(i+1, state|(x == 0 && state == 0 ? 0 : (1 << x)), less|(x < (s[i] - '0')));
		
		ans += x * 1ll * pw % mod * p.second % mod;
		if(ans >= mod) ans -= mod;
		
		ans += p.first;
		if(ans >= mod) ans -= mod;
		
		cnt += p.second;
		if(cnt >= mod) cnt -= mod;
	}
	return table[i][state][less] = {ans, cnt};
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> s >> m;
	
	for(int x=0;x<m;x++){
		cin >> c[x];
		must |= (1 << c[x]);
	}
	
	fill(*table[0], *table[maxLN], make_pair(-1, 0));
	
	solve(0, 0, false);
	
	cout << table[0][0][0].first << "\n";
    return 0;
}

