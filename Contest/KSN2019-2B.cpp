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

ll ask(ll n, ll m){
	cout << "SCAN " << n << " " << m << endl;
	ll ans;
	cin >> ans;
	
	return ans;
}

void ans(pair<ll, ll> a, pair<ll, ll> b){
	cout << "DIG " << a.first << " " << a.second << endl;
	cout << "DIG " << b.first << " " << b.second << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		ll n, m;
		cin >> n >> m;
		
		ll point[4] = {ask(1, 1), ask(1, m), ask(n, 1), ask(n, m)};
		
		vector<pair<pair<ll, ll>, pair<ll, ll>>> v;
		
		for(int a=1;a<=2;a++){
			ll tmp = (a == 1 ? point[0] + m + 1 - point[a] : point[0] + point[a] + 3 - n);
			
			bool valid = true;
			pair<ll, ll> tmpAns1, tmpAns2;
			if(tmp % 2 == 0){
				tmpAns1 = {abs(point[0]+2-tmp/2) , tmp/2};
			} else {
	//			cout << a << " fail1\n";
				valid = false;
			}
			
			int b = (a == 1 ? 2 : 1);
			tmp = (b == 1 ? (n + 1 + point[b] - point[3]) : (2ll*n + m - point[b] - 1 - point[3]));
			if(tmp % 2 == 0){
				tmpAns2 = {tmp/2, abs(n+m-point[3]-tmp/2)};
			} else {
	//			cout << a << " fail2\n";
				valid = false;
			}
			
			if(tmpAns1.first <= 0 || tmpAns1.second <= 0 || tmpAns2.first <= 0 || tmpAns2.second <= 0 || tmpAns1.first > n || tmpAns1.second > m || tmpAns2.first > n || tmpAns2.second > m){
	//			cout << a << " " << tmpAns1.first << "," << tmpAns1.second << " " << tmpAns2.first << "," << tmpAns2.second << " fail3\n";
				valid = false;
			}
			
			if(valid){
				v.push_back({tmpAns1, tmpAns2});
			}
		}
		
		ll mid = ((v[0].first != v[1].first && v[0].first != v[1].second) ? ask(v[0].first.first, v[0].first.second) : ask(v[0].second.first, v[0].second.second));
		if(mid == 0){
			ans(v[0].first, v[0].second);
		} else {
			ans(v[1].first, v[1].second);
		}
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

