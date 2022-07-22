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
	
	ui n, m;
	cin >> n >> m;
	
	ui data[n];
	for(ui x=0;x<n;x++){
		cin >> data[x];
	}
	
	ull ans = 0;
	for(ui x=0;x<n-m;x++){
		ull cost = 0;
		for(ui y=x;y<=x+m;y++){
			cost += data[y];
		}
		ans = (cost > ans ? cost : ans);
	}
	
	cout << ans << "\n";
    return 0;
}

