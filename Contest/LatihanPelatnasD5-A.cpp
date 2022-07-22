#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
		
	int n, m, q;
	cin >> n >> m >> q;
	
	int grid[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			char c;
			cin >> c;
			
			grid[x][y] = (c == '1');
		}
	}
	
	int x1[q], x2[q], y1[q], y2[q];
	for(int x=0;x<q;x++){
		cin >> x1[x] >> y1[x] >> x2[x] >> y2[x];
		x1[x]--; y1[x]--; x2[x]--; y2[x]--;
	}
	
	int prefix[n][m][3];
	
	int ans[q];
	fill(ans, ans+q, 0);
	
	for(int x=0;x<n;x++){
		int sum = 0, sum2 = 0, sum3 = 0;
		for(int y=0;y<m;y++){
			if(grid[x][y]){
				sum++;
			}
			if(x+1 < n && grid[x+1][y] && grid[x][y]){
				sum2++;
			}
			if(y+1 < m && grid[x][y+1] && grid[x][y]){
				sum3++;
			}
			
			for(int i=0;i<3;i++){
				if(x > 0) prefix[x][y][i] = prefix[x-1][y][i];
				else prefix[x][y][i] = 0;
			}
			prefix[x][y][0] += sum;
			prefix[x][y][1] += sum2;
			prefix[x][y][2] += sum3;
		}
	}
	
	for(int x=0;x<q;x++){
		int sum[3];
		fill(sum, sum+3, 0);
		
		for(int i=0;i<3;i++){
			if(x2[x]-(i == 1) >= 0 && y2[x]-(i == 2) >= 0){
				sum[i] += prefix[x2[x]-(i == 1)][y2[x]-(i == 2)][i];
				if(x1[x] > 0) sum[i] -= prefix[x1[x]-1][y2[x]-(i == 2)][i];
				if(y1[x] > 0) sum[i] -= prefix[x2[x]-(i == 1)][y1[x]-1][i];
				if(x1[x] > 0 && y1[x] > 0) sum[i] += prefix[x1[x]-1][y1[x]-1][i];
			}
		}
		
		cout << sum[0]-sum[1]-sum[2] << "\n";
	}
	return 0;
}
