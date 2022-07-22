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

const int maxN = 1e5 + 5;

ll table[maxN][2]; // + -
ll cnt[maxN][2];

ll mulmod(ll a, ll b){
	ll ans = 0;
	
	while(b > 0){
		if(b&1) ans = (ans + a) % mod;
		
		b >>= 1;
		a = (a+a)%mod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	ll data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	fill(cnt[0], cnt[n], 0);
		
	table[0][0] = data[0];
	table[0][1] = 0;
	cnt[0][0] = 1;
	
	for(int x=1;x<n;x++){
		table[x][0] = (table[x-1][0] + table[x-1][1] + mulmod(cnt[x-1][0]+cnt[x-1][1], data[x])) % mod;
		table[x][1] = (table[x-1][0] - mulmod(cnt[x-1][0], data[x])) % mod;
		cnt[x][0] = (cnt[x-1][0] + cnt[x-1][1]) % mod;
		cnt[x][1] = cnt[x-1][0] % mod;
	}
	
	cout << (table[n-1][0] + table[n-1][1] + 2*mod) % mod << "\n";
    return 0;
}



