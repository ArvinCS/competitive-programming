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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	ll n, m, k;
	cin >> n >> m >> k;
	
	ll sum = 0;
	vector<int> v;
	for(int x=0;x<n;x++){
		int val;
		cin >> val;
		
		sum += val;
		v.push_back(val);
	}
	
	if(k == 1){
		cout << (m*n % mod * (m*n-1) % mod + (sum*m % k == 0)) % mod << "\n";
		return 0;
	}
	
	for(int x=0;x<2*m;x++){
		for(int y=0;y<n;y++){
			v.push_back(v[y]);
		}
	}
	
//	for(int x=0;x<v.size();x++){
//		cout << v[x] << " ";
//	}
//	cout << "\n";
	
	ll ans = ((sum*m) % k == 0);
	map<pair<int, int>, int> mp;
	for(int x=0;x<(m*n);x++){
		ll sum = 0;
		for(int y=x;y<v.size();y++){
			if(y >= (m*n+x)-1) break;
			
			sum += v[y];
			if(sum % k == 0){
//				cout << x%n << " " << y%n << "\n";
				mp[{x%n, y%n}]++;
				ans++;
			}
		}
	}

	for(auto p : mp){
		cout << p.first.first << " " << p.first.second << " -> " << p.second << "\n";
	}
	cout << ans << "\n";
    return 0;
}

