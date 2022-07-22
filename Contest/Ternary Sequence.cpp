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

	us t;
	cin >> t;
	
	while(t--){
		ll x1,y1,z1,x2,y2,z2;
		cin >> x1 >> y1 >> z1;
		cin >> x2 >> y2 >> z2;
		
		ll low = min(z1,y2); // jadi +2
		ll ans = low * 2;
		z1 -= low;
		y2 -= low;
		
		ans -= max(0ll, z2-z1-x1) * 2;
		
		cout << ans << "\n";
				
	}

    return 0;
}

