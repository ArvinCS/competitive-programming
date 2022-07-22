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

ull mul(ull x, ull y){
	ull remain = 0;
	x %= mod;
	
	while(y > 0){
		if(y % 2 == 1) remain = (remain + x) % mod;
		
		x = (x * 2) % mod;
		y /= 2;
	}
	return remain % mod;
}

ull pow(ull x, ull i){
	if(i == 0) return 1ull;
	if(i == 1) return x;
	
	ull tmp = pow(x, i/2) % mod;
	if(i % 2 == 1) return mul(x, mul(tmp, tmp));
	else return mul(tmp, tmp);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ull k, x, n, m;
	cin >> n >> m >> k >> x;
	
	cout << pow(k+1, n+m-1) << "\n";
	
    return 0;
}

