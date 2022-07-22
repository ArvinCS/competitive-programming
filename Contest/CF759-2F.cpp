#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;
const ll mod = 998244353;

ll powmod(ll x, ll y){
	ll ans = 1;
	
	x %= mod;
	while(y){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x * x) % mod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	stack<array<ll, 2>> st;
	
	ll sum = 0;
	for(int x=0;x<n;x++){
		ll val = (sum+(x == 0)) % mod;
		
		sum = (sum-a[x]*val % mod + mod) % mod;
		
		while(!st.empty() && st.top()[0] > a[x]){
			ll curval = st.top()[0], curcnt = st.top()[1];
			st.pop();
			
			sum = (sum + curcnt*(curval-a[x])) % mod;
			val = (val+curcnt) % mod; 
		}
		st.push({a[x], val});
	}
	
	cout << (n&1 ? mod-sum : sum)%mod << "\n";
    return 0;
}

