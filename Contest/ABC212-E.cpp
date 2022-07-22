#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<pair<int, int>> e;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		e.push_back({a, b});
	}
	
	ll table[k+1][n];
	fill(table[0], table[k+1], 0);
	
	ll sum = 1;
	table[0][0] = 1;
	for(int i=1;i<=k;i++){
		for(auto p : e){
			table[i][p.first] += table[i-1][p.second];
			table[i][p.second] += table[i-1][p.first];
		}
		
		ll cur = 0;
		for(int x=0;x<n;x++){
			ll val = (sum-table[i][x]+mod) % mod;
			val = (val-table[i-1][x]+mod) % mod;
			
			table[i][x] = val;
			cur += val;
			cur %= mod;
		}
		sum = cur;
	}
	
	cout << table[k][0] << "\n";
    return 0;
}

