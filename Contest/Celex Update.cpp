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
	
	ui t;
	cin >> t;
	
	while(t--){
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ll ans = (x2-x1) * 1ll * (y2-y1);
		cout << ans+1 << "\n";
	}
	
    return 0;
}

