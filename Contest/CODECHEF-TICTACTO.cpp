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

const int maxN = 1e3 + 5;
const int logN = log2(maxN)+1;

int table[logN][maxN][logN][maxN];
int b[maxN][maxN];
int a[maxN][maxN][2];
int n, m;

void build(){
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			table[0][x][0][y] = b[x][y];
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

int rmq(int x1, int y1, int x2, int y2){
	int lgRow = log2(x2-x1+1);
	int lengthRow = (1 << lgRow);
	int lgCol = log2(y2-y1+1);
	int lengthCol = (1 << lgCol);
	
	int mn1 = max(table[lgRow][x1][lgCol][y1], table[lgRow][x1][lgCol][y2-lengthCol+1]);
	int mn2 = max(table[lgRow][x2-lengthRow+1][lgCol][y1], table[lgRow][x2-lengthRow+1][lgCol][y2-lengthCol+1]);
	
	return max(mn1, mn2);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int t;
	cin >> t;
	
	while(t--){
		int k;
		cin >> n >> m >> k;
		
		fill(*a[0], *a[n+1], 0);
		for(int x=0;x<n*m;x++){
			int u, v;
			cin >> u >> v;
			
			u--; v--;
			a[u][v][(x%2)]++;
			b[u][v] = x;
		}
		
		build();
		
		for(int x=0;x<n;x++){
			int cnt[2];
			cnt[0] = cnt[1] = 0;
			
			for(int y=0;y<m;y++){
				cnt[0] += a[x][y][0];
				cnt[1] += a[x][y][1];
				
				a[x][y][0] = cnt[0];
				a[x][y][1] = cnt[1];
				
				if(x > 0){
					a[x][y][0] += a[x-1][y][0];
					a[x][y][1] += a[x-1][y][1];
				}
//				cout << rmq(x,y,x,y) << " ";
			}
//			cout << "\n";
		}
		
		int win = -1, time = inf_int;
		for(int x=0;x+k-1<n;x++){
			for(int y=0;y+k-1<m;y++){
				int exc0 = (x > 0 ? a[x-1][y+k-1][0] : 0) + (y > 0 ? a[x+k-1][y-1][0] : 0) - ((x > 0 && y > 0) ? a[x-1][y-1][0] : 0);
				int exc1 = (x > 0 ? a[x-1][y+k-1][1] : 0) + (y > 0 ? a[x+k-1][y-1][1] : 0) - ((x > 0 && y > 0) ? a[x-1][y-1][1] : 0);
				
				int alice = a[x+k-1][y+k-1][0] - exc0;
				int bob = a[x+k-1][y+k-1][1] - exc1;
				
//				cout << x << "," << y << " -> " << alice << " " << bob << "\n";
				if(alice == 0 && bob == k*k){
					if(time > rmq(x, y, x+k-1, y+k-1)){
						time = rmq(x, y, x+k-1, y+k-1);
						win = 1;
					}
				} else if(alice == k*k && bob == 0){
					if(time > rmq(x, y, x+k-1, y+k-1)){
						time = rmq(x, y, x+k-1, y+k-1);
						win = 0;
					}
				}
			}
		}
		
		if(win == -1){
			cout << "Draw\n";
		} else if(win == 0){
			cout << "Alice\n";
		} else if(win == 1){
			cout << "Bob\n";
		}
	}
    return 0;
}

