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

const ll maxX = 1e5;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, m;
	cin >> n >> m;
	
	int table[m+5];
	fill(table, table+m+5, -1);
	
	table[0] = 0;
	for(int x=1;x<=n;x++){
		ll a, b, c;
		cin >> a >> b >> c;
		
		bool done[m+1];
		fill(done, done+m+1, false);
		
		for(ll y=m;y>=0;y--){
			if(table[y] >= 0 && !done[y]){
				ll k = y;
				ll times = 0;
				while(times <= c){
					if(times > 0){
						if(a == 1){
							k = ceil(k + b*1.0/maxX);
						} else {
							k = ceil(k * (b*1.0/maxX));
						}
					}
					if(k > m || done[k]) break;
					if(table[k] == -1) table[k] = x;
					done[k] = true;
					times++;
				}
			}
		}
	}
	
	for(int x=1;x<=m;x++){
		cout << table[x] << " \n"[x == m];
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

