#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

const int mxN = 5 * 1e3;
int mod, data[mxN + 5], table[mxN + 5];
us n, m, b;

int dp(int start, int bugs, bool visited[]){
	visited[start] = true;
	
	
	
	ll total = 0;
	for(int x=0;x<n;x++){
		if(visited[x]) continue;
		visited[x] = true;
		total += dp(x, bugs+data[x], visited);
		visited[x] = false;
	}
	
	return total % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> m >> b >> mod;
	
	for(us x=0;x<n;x++) cin >> data[x];
	
	fill(table, table+n+1, inf_int);
	
	cout << dp(0) << "\n";
    return 0;
}

