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
	
	ull table[r][c];
	ull ans = 0;
	for(ui x=0;x<r;x++){
		for(ui y=0;y<c;y++){
			cin >> table[x][y];
			if(x > 0) table[x][y] += table[x-1][y];
			if(y > 0) table[x][y] += table[x][y-1];
			if(x > 0 && y > 0) table[x][y] -= table[x-1][y-1];
			ans = max(ans, table[x][y]);
//			cout << table[x][y] << " ";
		}
//		cout << "\n";
	}
	
	cout << ans << "\n";
    return 0;
}

