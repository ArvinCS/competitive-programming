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

ll fac[maxN];

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y>0){
		if(y&1) ans = (ans*x) % mod;
		
		y >>= 1;
		x = (x*x) % mod;
	}
	return ans;
}

ll combin(ll x, ll y){
	return fac[x] * powmod(fac[x-y], mod-2) % mod * powmod(fac[y], mod-2) % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	fac[0] = fac[1] = 1;
	for(int x=2;x<maxN;x++){
		fac[x] = (x*1ll*fac[x-1]) % mod;
	}
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	sort(a, a+n);
	
	ll sum = 0;
	for(int x=0;x<n;x++){
		sum += a[x];
	}
	
	if(sum%n != 0){
		cout << "0\n";
		return 0;
	}
	
	map<int, int> mp;
	vector<int> great, less, equal;
	for(int x=0;x<n;x++){
		mp[a[x]]++;
		
		if(a[x] > sum/n){
			great.push_back(a[x]);
		} else if(a[x] < sum/n){
			less.push_back(a[x]);
		} else {
			equal.push_back(a[x]);
		}
	}
	
	if(equal.size() == n){
		cout << "1\n";
		return 0;
	}
	if(great.size() == 1 || less.size() == 1){
		ll ans = fac[n];
		
		for(auto p : mp){
			ans = (ans * powmod(fac[p.second], mod-2)) % mod;
		}
		
		cout << ans << "\n";
		return 0;
	}
	
	ll ans = 2 * combin(n, equal.size()) % mod * fac[great.size()] % mod * fac[less.size()] % mod;
	for(auto p : mp){
		if(p.first != sum/n) ans = (ans * powmod(fac[p.second], mod-2)) % mod;
	}
	
	cout << ans << "\n";
    return 0;
}

