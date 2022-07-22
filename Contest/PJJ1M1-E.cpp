#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e3 + 5;
const int logN = log2(maxN)+1;

int a[maxN][maxN];
int n, m;

struct SparseTable {
	int table[logN][maxN][logN][maxN];
	
	void build(){
		for(int x=0;x<n;x++){
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
		if(x1 > x2 || y1 > y2) return 0;
		
		int lgRow = log2(x2-x1+1);
		int lengthRow = (1 << lgRow);
		int lgCol = log2(y2-y1+1);
		int lengthCol = (1 << lgCol);
		
		int mx1 = max(table[lgRow][x1][lgCol][y1], table[lgRow][x1][lgCol][y2-lengthCol+1]);
		int mx2 = max(table[lgRow][x2-lengthRow+1][lgCol][y1], table[lgRow][x2-lengthRow+1][lgCol][y2-lengthCol+1]);
		
		return max(mx1, mx2);
	}	
};

SparseTable st;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> m;
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> a[x][y];
		}
	}	
	
	for(int x=0;x<n;x++){
		int pos = -1;
		for(int y=0;y<m;y++){
			if(a[x][y] == 0) pos = y;
			
			st.table[0][x][0][y] = min((x > 0 && y > 0 ? st.table[0][x-1][0][y-1] : 0) + 1, y-pos);
		}
	}
	for(int y=0;y<m;y++){
		int pos = -1;
		for(int x=0;x<n;x++){
			if(a[x][y] == 0) pos = x;
			
			st.table[0][x][0][y] = min(min(st.table[0][x][0][y], (x > 0 && y > 0 ? st.table[0][x-1][0][y-1] : 0)+1), x-pos);
		}
	}
	
	st.build();
	
	int t;
	cin >> t;
	
	while(t--){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		x1--; y1--; x2--; y2--;
		
		int ans = 0;
		int left = 1, right = min(n, m);
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(x1+mid-1 <= x2 && y1+mid-1 <= y2){
				if(st.rmq(x1+mid-1, y1+mid-1, x2, y2) >= mid){
					ans = max(ans, mid);
					left = mid+1;
				} else {
					right = mid-1;
				}
			} else {
				right = mid-1;
			}
		}
		
		cout << ans << "\n";
	}
    return 0;
}

