#include <iostream>
#include <cmath>

using namespace std;

#define ull unsigned long long
#define ll long long
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us n;
	cin >> n;
	if(n <= 2){
		cout << n << "\n";
		for(int x=0;x<n;x++){
			cout << "1 " << x+1 << "\n";
		}
	} else {
		// m = baris ujung atas
		// (m-1) = kolom ujung kanan
		// m + (m-1) = n
		// m + m - 1 = n
		// m + m = n + 1
		// 2m = n + 1
		// m = n + 1 / 2
		int m = ceil((n+1) / 2.0);
		cout << m << "\n";
		
		int row = 1, column = 0;
		while(n--){
			if(column < m){
				column++;
			} else {
				row++;
			}
			cout << row << " " << column << "\n";
		}
	}
    return 0;
}
