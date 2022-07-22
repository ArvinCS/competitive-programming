#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxK = 1e4 + 5;
const int maxN = 105;

ll table[maxK][maxN], new_table[maxK][maxN];
ll a[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, l, r, k;
	cin >> n >> l >> r >> k;
	
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	fill(table[0], table[maxK], 1e18);
	fill(new_table[0], new_table[maxK], 1e18);
	
	l--; r--;
	table[0][0] = 0;
	for(int x=0;x<r-l+1;x++){
		for(int y=0;y<=k;y++){
			ll mn = 1e18;
			for(int z=0;z<n;z++){
				mn = min(mn, table[y][z]);
				
				if(mn != 1e18 && y+abs(l+x-z) <= k){
					ll tmp = mn+a[z];
					
					if(new_table[y+abs(l+x-z)][z+1] >= tmp){
						new_table[y+abs(l+x-z)][z+1] = tmp;
					}
				}
			}
		}
		for(int y=0;y<=k;y++){
			for(int z=0;z<=n;z++){
				table[y][z] = new_table[y][z];
				new_table[y][z] = 1e18;
			}
		}
	}
	
	ll ans = 1e18;
	for(int y=0;y<=k;y++){
		for(int z=0;z<=n;z++){
			ans = min(ans, table[y][z]);
		}
	}
	assert(ans < 1e18);
	cout << ans << "\n";
    return 0;
}

