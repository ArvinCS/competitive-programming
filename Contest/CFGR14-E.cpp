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

const int maxN = 450;

ll n, m;
ll table[maxN][maxN];

void add(ll &a, ll b){
	a += b;
	a %= m;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n >> m;
	
	fill(table[0], table[n+10], 0);

	table[1][1] = 1;
	for(int x=1;x<=n;x++){
		for(int y=1;y<=x;y++){
			// create new component
			add(table[x+1][y+1], table[x][y] * (y+1));
			
			// insert into existing component
			add(table[x+1][y], table[x][y] * (2*y));
			
			// insert into existing component but skip element (x+1), so that element (x+1) become automatic
			add(table[x+2][y], table[x][y] * (2*y));
			
			// merge component
			add(table[x+2][y-1], table[x][y] * 2 * (y-1));
			add(table[x+3][y-1], table[x][y] * (y-1));
		}
	}
	
	cout << table[n][1] << "\n";
    return 0;
}

