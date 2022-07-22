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
	
	ll n;
	cin >> n;
	
	ui ans = 0;
	for(ui x=1;x<n;x++){
		for(ui y=x+1;x*1ll*y<n;y++){
			ll result = n - (x*1ll*y);
			if(result != x && result != y) ans++;
//			cout << result << "+" << x << "*" << y << "\n";
		}
	}
	
	cout << ans * 2 << "\n";
	
    return 0;
}

