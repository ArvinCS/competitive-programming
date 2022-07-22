#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxProduct = 1e5 + 5;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n, m;
	cin >> n >> m;
	
	vector<ll> v[n];
	for(ll x=0;x<n;x++){
		int l;
		cin >> l;
		
		for(int y=0;y<l;y++){
			ll val;
			cin >> val;
			
			v[x].push_back(val);
		}
	}
	
	map<ll, ll> table[n+1];
	
	table[0][1] = 1;
	for(ll x=0;x<n;x++){
		for(int y=0;y<v[x].size();y++){
			for(auto p : table[x]){
				if(v[x][y] > m/p.first) continue;
				
				table[x+1][p.first*v[x][y]] += p.second;
			}
		}
	}
	
	cout << table[n][m] << "\n";
    return 0;
}

