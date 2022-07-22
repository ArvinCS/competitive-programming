#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e3 + 5;
const int logN = log2(maxN)+1;

ll table[logN][maxN][logN][maxN];
ll mx[maxN][maxN];
int n, m;

void build(){
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			table[0][x][0][y] = mx[x][y];
		}
		
		for(int y=1;y<logN;y++){
			int length = (1 << y);
			for(int z=0;z+length<=m;z++){
				table[0][x][y][z] = max(table[0][x][y-1][z], table[0][x][y-1][z+length/2]);
			}
		}
	}
	
	for(int a=1;a<logN;a++){
		int lengthA = (1 << a);
		for(int b=0;b+lengthA<=n;b++){
			for(int c=0;c<logN;c++){
				int lengthC = (1 << c);
				for(int d=0;d+lengthC<=m;d++){
					table[a][b][c][d] = max(table[a-1][b][c][d], table[a-1][b+lengthA/2][c][d]);
				}
			}
		}
	}
}

ll rmq(int x1, int y1, int x2, int y2){
	int lgRow = log2(x2-x1+1);
	int lengthRow = (1 << lgRow);
	int lgCol = log2(y2-y1+1);
	int lengthCol = (1 << lgCol);
	
	ll mx1 = max(table[lgRow][x1][lgCol][y1], table[lgRow][x1][lgCol][y2-lengthCol+1]);
	ll mx2 = max(table[lgRow][x2-lengthRow+1][lgCol][y1], table[lgRow][x2-lengthRow+1][lgCol][y2-lengthCol+1]);
	
	return max(mx1, mx2);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int h1, w1, h2, w2;
	cin >> n >> m >> h1 >> w1 >> h2 >> w2;
	
	ll a[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> a[x][y];
		}
	}
	
	ll prefix[n][m];
	for(int x=0;x<n;x++){
		ll sum = 0;
		for(int y=0;y<m;y++){
			sum += a[x][y];
			
			prefix[x][y] = sum;
			if(x > 0){
				prefix[x][y] += prefix[x-1][y];
			}
		}
	}
	
	fill(mx[0], mx[maxN], 0);
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			ll sum = prefix[min(n-1, x+min(h1, h2)-1)][min(m-1, y+min(w1, w2)-1)];
			if(x > 0) sum -= prefix[x-1][min(m-1, y+min(w1, w2)-1)];
			if(y > 0) sum -= prefix[min(n-1, x+min(h1, h2)-1)][y-1];
			if(x > 0 && y > 0) sum += prefix[x-1][y-1];	
			
			mx[x][y] = sum;
		}
	}
	
	build();
	
	ll ans = 0;
	for(int x=0;x<n-h1+1;x++){
		for(int y=0;y<m-w1+1;y++){
			ll sum = prefix[x+h1-1][y+w1-1];
			if(x > 0) sum -= prefix[x-1][y+w1-1];
			if(y > 0) sum -= prefix[x+h1-1][y-1];
			if(x > 0 && y > 0) sum += prefix[x-1][y-1];
			
			ans = max(ans, sum-rmq(x, y, max(x, x+h1-1-h2+1), max(y, y+w1-1-w2+1)));
		}
	}
	
	cout << ans << "\n";
    return 0;
}

