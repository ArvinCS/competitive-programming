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
	
	short n, m, o;
	cin >> n >> m >> o;
	
	int data[n][m];
	for(short x=0;x<n;x++){
		for(short y=0;y<m;y++){
			cin >> data[x][y];
		}
	}
	
	int rows[n][2], ans = -inf_int, cnt = 0;
	for(short l=0;l<m;l++){
		fill(rows[0], rows[n], 0);
		for(short r=l;r<m;r++){
			for(short i=0;i<n;i++){
				rows[i][0] += (data[i][r] < 9999 ? data[i][r] : 0);
				rows[i][1] += (data[i][r] == 9999);
			}
			int best = 0, tmp = 0;
			for(short x=0;x<n;x++){
				best = 0; tmp = 0;
				for(short y=x;y<n;y++){
					best += rows[y][0];
					tmp += rows[y][1];
					
					if(tmp > o) break;
					if(best > ans || (best == ans && tmp < cnt)){
						ans = best;
						cnt = tmp;
					}
				}
			}
		}
	}
	
	cout << ans << " " << cnt << "\n";
    return 0;
}

