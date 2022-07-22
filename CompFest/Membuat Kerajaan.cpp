#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us r, c;
	cin >> r >> c;
	
	ll table[r][c];
	for(us x=0;x<r;x++){
		for(us y=0;y<c;y++){
			cin >> table[x][y];
			
			if(x > 0) table[x][y] += table[x-1][y];
			if(y > 0) table[x][y] += table[x][y-1];
			if(x > 0 && y > 0) table[x][y] -= table[x-1][y-1];			
//			cout << table[x][y] << " ";
		}
//		cout << "\n";
	}
	
	ll ans = table[0][0];
	for(us i=0;i<r;i++){
		for(us j=0;j<c;j++){
			for(us k=i;k<r;k++){
				for(us l=j;l<c;l++){
					ans = max(ans, table[k][l] - (i > 0 ? table[i-1][l] : 0) - (j > 0 ? table[k][j-1] : 0) + (i > 0 && j > 0 ? table[i-1][j-1] : 0));	
				}
			}		
		}
	}
	cout << ans << "\n";
    return 0;
}

