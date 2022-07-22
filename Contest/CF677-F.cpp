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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	int a[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> a[x][y];
		}
	}
	
	int row[n][k];
	fill(row[0], row[n], -1);
	
	for(int x=0;x<n;x++){
		int sum[m][k];
		fill(sum[0], sum[m], -1);
		
		for(int y=0;y<m;y++){
			for(int i=m/2-1;i>=0;i--){
				if(i == 0){
					sum[i][a[x][y]%k] = max(sum[i][a[x][y]%k], a[x][y]);
				} else {
					for(int z=0;z<k;z++){
						if(sum[i-1][z] != -1){
							sum[i][(z+a[x][y])%k] = max(sum[i][(z+a[x][y])%k], sum[i-1][z] + a[x][y]);
						}
					}
				}
			}
		}
		
		for(int y=0;y<k;y++){
			for(int i=m/2-1;i>=0;i--){
				row[x][y] = max(row[x][y], sum[i][y]);
			}
		}
		row[x][0] = max(row[x][0], 0);
	}
	
	int ans[n][k];
	fill(ans[0], ans[n], -1);
	
	for(int x=0;x<k;x++){
		ans[0][x] = row[0][x];
	}
	
	for(int x=1;x<n;x++){
		for(int y=0;y<k;y++){
			for(int z=0;z<k;z++){
				if(ans[x-1][z] != -1 && row[x][y] != -1){
					ans[x][(y+z)%k] = max(ans[x][(y+z)%k], ans[x-1][z] + row[x][y]);
				}
			}
		}
	}
	
	cout << (ans[n-1][0] != -1 ? ans[n-1][0] : 0) << "\n";
    return 0;
}

