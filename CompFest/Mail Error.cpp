#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

us table[1000][1000];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string a, b;
	cin >> a >> b;
	
	us table[a.length()][b.length()];
	fill(table[0], table[a.length()], 0);		
	
	table[0][0] = (a[0] == b[0]);

	for(us x=0;x<a.length();x++){
		for(us y=0;y<b.length();y++){
			if(x == 0 && y == 0) continue;
			if(a[x] == b[y]){
				table[x][y] = 1 + (x > 0 && y > 0 ? table[x-1][y-1] : 0);
			} else {
				table[x][y] = max(x > 0 ? table[x-1][y] : 0, y > 0 ? table[x][y-1] : 0);
			}
		}
	}
	
//	for(us y=0;y<b.length();y++){
//		for(us x=0;x<a.length();x++){
//			cout << "(" << a[x] << "-" << b[y] << ")" << table[x][y] << " ";
//		}
//		cout << "\n";
//	}
	cout << table[a.length()-1][b.length()-1] << "\n";
	return 0;
}

