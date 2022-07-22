#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;

void chadd(ll &a, ll b){
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int p[n];
	for(int x=0;x<n;x++){
		cin >> p[x];
	}
	
	ll table[n+1], new_table[n+1];
	fill(table, table+n+1, 0);
	
	table[1] = 1;
	for(int x=1;x<n;x++){
		fill(new_table, new_table+n+1, 0);
		
		ll sum = 0;
		for(int y=0;y<=n;y++){
			chadd(new_table[y], sum);
			chadd(sum, table[y]);
			if(y+1 <= n){
				chadd(new_table[y+1], table[y]);
			}
		}
		
		for(int y=0;y<=n;y++) table[y] = new_table[y];
	}
	
	ll ans = 0;
	for(int x=0;x<=n;x++) chadd(ans, table[x]);
	
	cout << ans << "\n";
    return 0;
}

