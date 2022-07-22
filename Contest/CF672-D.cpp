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

const int maxN = 3 * 1e5 + 5;

ll fac[maxN];
int arr[2*maxN];

ll power(ll a, ll b){
	ll ans = 1;
	a %= smod;
	while(b > 0){
		if(b & 1) ans = (ans * a) % smod;
		
		b >>= 1;
		a = (a*a) % smod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, k;
	cin >> n >> k;
	
	fac[0] = fac[1] = 1;
	for(ll x=2;x<=n;x++){
		fac[x] = (fac[x-1] * x) % smod;
	}
	
	pair<int, int> data[n];
	for(int x=0;x<n;x++){
		cin >> data[x].first >> data[x].second;
	}
		
	vector<pair<int, int>> v;
	for(int x=0;x<n;x++){
//		cout << data[x].first << " " << data[x].second << "\n";
		v.push_back(make_pair(data[x].first, 1));
		v.push_back(make_pair(data[x].second+1, -1));
	}
	
	sort(v.begin(), v.end());
	
	ll ans = 0;
	ll cur = 0;
	for(int x=0;x<v.size();x++){
		if(v[x].second == 1){
			if(cur >= k-1){
//				cout << cur << " " << fac[cur] << " " << power(fac[k-1], smod-2) << " " << power(fac[cur-k+1], smod-2) << "\n";
				ans += ((fac[cur] * power(fac[k-1], smod-2)) % smod * power(fac[cur-k+1], smod-2)) % smod;
				ans %= smod;
			}
		}
		cur += v[x].second;
	}
	
	cout << ans % smod << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

