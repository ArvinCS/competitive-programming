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
	
	us n, m;
	cin >> n >> m;
	
	us data[n][m];
	for(us x=0;x<n;x++){
		for(us y=0;y<m;y++) cin >> data[x][y];
	}
	
	for(us x=0;x<m;x++){
		for(us y=0;y<n;y++){
			if(y > 0) cout << " ";
			cout << data[y][x];
		}
		cout << "\n";
	}
    return 0;
}
