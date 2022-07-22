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

vector<pair<ll, int>> data;
vector<int> v[65];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	for(int x=0;x<n;x++){
		ll tmp;
		cin >> tmp;
		
		data.push_back({tmp, x});
	}
	
	sort(data.begin(), data.end());
	
	for(int x=0;x<data.size();x++){
		for(int y=0;y<64;y++){
			ll bit = (1ll << y);
			if(data[x].first&bit){
				v[y].push_back(x);
			}
		}
	}
	
	for(int i=63;i>=0;i--){
		ll bit = (1ll << i);
		if(v[i].size() > 0 && v[i].size() % 2 == 0){
			int idx = v[i][0];
			data[idx].first ^= bit;
			for(int j=i-1;j>=0;j--){
				ll bit = (1ll << j);
				if(v[j].size() % 2 == 0){
					data[idx].first ^= bit;
				}
			}
			break;	
		}
	}
	
	ll ans = 0;
	for(int x=0;x<data.size();x++){
		ans ^= data[x].first;
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

