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
	
	int t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		
		ll data[n], mn = inf_ll, mnIdx = -1;
		for(int x=0;x<n;x++){
			cin >> data[x];
			
			if(mn > data[x]){
				mn = data[x];
				mnIdx = x;
			}
		}
		
		ll mn2 = -1;
		for(ll x=mn+1;x<=mn*3000;x++){
			if(__gcd(mn, x) == 1){
				mn2 = x;
				break;
			}
		}
		
		vector<tuple<ll, ll, ll, ll>> v;
		for(int x=mnIdx-1;x>=0;x--){
			if(data[x+1] == mn){
				data[x] = mn2;
				v.push_back(make_tuple(x+1, mnIdx+1, mn2, mn));
			} else {
				data[x] = mn;
				v.push_back(make_tuple(x+1, mnIdx+1, mn, mn));
			}
		}
		for(int x=mnIdx+1;x<n;x++){
			if(data[x-1] == mn){
				data[x] = mn2;
				v.push_back(make_tuple(x+1, mnIdx+1, mn2, mn));
			} else {
				data[x] = mn;
				v.push_back(make_tuple(x+1, mnIdx+1, mn, mn));
			}
		}
		
		cout << v.size() << "\n";
		for(auto t : v){
			cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << "\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

