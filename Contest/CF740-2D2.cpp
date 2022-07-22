#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

const int maxN = 4e6 + 5;

ll m, table[maxN], suffix[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n;
	cin >> n >> m;
	
	fill(table, table+maxN, 0);
	fill(suffix, suffix+maxN, 0);
	
	suffix[n] = table[n] = 1;
	for(int x=n-1;x>=1;x--){
		ll cnt = suffix[x+1];
		
		for(int y=2;y*x<=n;y++){
			cnt = (cnt + suffix[x*y] - suffix[min(n+1, x*y+y)] + m) % m;
		}
		
		table[x] = cnt;
		suffix[x] = (suffix[x+1] + table[x]) % m;
	}

	cout << table[1] << "\n";
    return 0;
}

