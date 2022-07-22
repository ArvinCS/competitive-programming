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

	int n;
	cin >> n;
	
	ll data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	vector<ll> v[2];
	for(int x=0;x<n;x++){
		v[(data[x]%2)].push_back(data[x]);
	}
	
	vector<ll> ans[2];
	for(auto e : v[0]) ans[0].push_back(e);
	for(auto e : v[1]) ans[1].push_back(e);
		
	map<ll, vector<ll>> mp;
	for(int x=0;x<v[0].size();x++){
		ll cur = v[0][x], cnt = 0;
		while(cur % 2 == 0){
			cur /= 2;
			cnt++;
		}
		
		mp[cnt].push_back(v[0][x]);
	}
		
	ll best = 0, idx = 0;
	for(auto m : mp){
		if(m.second.size() > best){
			best = m.second.size();
			idx = m.first;
		}
	}
	
	for(auto m : mp){
		if(m.first != idx){
			for(auto e : m.second) ans[1].push_back(e);
		}
	}
	
	if(ans[0].size() <= ans[1].size()){
		cout << ans[0].size() << "\n";
		for(int x=0;x<ans[0].size();x++){
			if(x > 0) cout << " ";
			cout << ans[0][x];
		}
		cout << "\n";
	} else {
		cout << ans[1].size() << "\n";
		for(int x=0;x<ans[1].size();x++){
			if(x > 0) cout << " ";
			cout << ans[1][x];
		}
		cout << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

