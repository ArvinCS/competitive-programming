#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int a[m], b[m], state[n];
	int mx[n][3];
	fill(mx[0], mx[n], -1);
	fill(state, state+n, 0);
	for(int x=0;x<m;x++){
		cin >> a[x] >> b[x];
		a[x]--; b[x]--;
		
		if(a[x] < b[x]){
			state[a[x]] |= 1;
			mx[a[x]][1] = max(mx[a[x]][1], b[x]);
		} else {
			state[b[x]] |= 2;
			mx[b[x]][2] = max(mx[b[x]][2], a[x]);
		}
	}
	
	ll table[n][26][4];
	fill(*table[0], *table[n], 0);
	
	auto madd = [&](ll &a, ll b) -> void {
		a += b;
//		if(a >= mod) a -= mod;
	};
	
	int last[3];
	last[1] = mx[0][1];
	last[2] = mx[0][2];
	for(int x=0;x<26;x++){
		madd(table[0][x][state[0]], 1);
	}
	for(int x=1;x<n;x++){
		for(int y=0;y<26;y++){
			for(int z=0;z<4;z++){
				int cur = z;
				if(last[1] < x){
					cur = (cur|1)^1;
				}
				if(last[2] < x){
					cur = (cur|2)^2;
				}
				
				if(!(cur&1)){
					for(int y2=y+1;y2<26;y2++){
						madd(table[x][y2][((cur|2)^2) | state[x]], table[x-1][y][z]);
					}
				}
				if(!(cur&2)){
					for(int y2=0;y2<y;y2++){
						madd(table[x][y2][((cur|1)^1) | state[x]], table[x-1][y][z]);
					}
				}
				
				madd(table[x][y][cur|state[x]], table[x-1][y][z]);
			}
		}
		
//		cout << x << " -> " << last[1] << " " << last[2] << "\n";
		last[1] = max(last[1], mx[x][1]);
		last[2] = max(last[2], mx[x][2]);
	}
	
	ll ans = 0;
	for(int y=0;y<26;y++){
		for(int z=0;z<4;z++){
			madd(ans, table[n-1][y][z]);
		}
	}
	cout << ans << "\n";
    return 0;
}

