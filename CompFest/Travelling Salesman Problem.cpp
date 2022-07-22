#include <iostream>
#include <cmath>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

us n;
ui adj[15][15];
ui table[15][32769];

ui dp(us i, int bitmask){
	if(bitmask == pow(2,n) - 1){
		return adj[i][0];
	}
	if(table[i][bitmask] != inf_int){
		return table[i][bitmask];
	}

	ui ans = inf_int;
	for(us x=0;x<n;x++){
		if((bitmask & (1 << x)) == 0){
//			cout << i << " -> " << x  << "(" << bitmask << ")" << (bitmask & (1 << x)) << ")\n";
			ans = min(ans, adj[i][x] + dp(x, (bitmask | 1 << x)));
		}
	}
	
	table[i][bitmask] = ans;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;
	
	fill(adj[0], adj[n], inf_int);
	fill(table[0], table[n], inf_int);
	
	for(us x=0;x<n;x++){
		for(us y=0;y<n;y++){
			ui tmp;
			cin >> tmp;
			
			adj[x][y] = min(tmp, adj[x][y]);
			adj[y][x] = min(tmp, adj[y][x]);
		}
	}
	
	cout << dp(0, 1) << "\n";
    return 0;
}

