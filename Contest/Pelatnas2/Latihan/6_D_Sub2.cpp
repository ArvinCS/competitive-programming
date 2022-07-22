#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const ll div2 = 500000004;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll a[n+1];
	for(int x=0;x<=n;x++){
		cin >> a[x];
	}
	
	assert(n == 2);
	
	ll cnt[n+1];
	cnt[0] = 1;
	for(int x=1;x<=n;x++){
		cnt[x] = (a[x-1] * cnt[x-1]) % mod;
	}
	
	cout << (cnt[1] + cnt[2]) % mod << " " << (cnt[2] + a[0] * a[1] % mod * (a[1]-1) % mod * div2 % mod + (cnt[1]*(cnt[1]-1) % mod * div2 % mod)) % mod << " " << (cnt[2]*(cnt[1]-1) % mod) << " " << ((a[0]-1) * a[1] % mod * cnt[2] % mod * div2 % mod) << "\n";
	
    return 0;
}

