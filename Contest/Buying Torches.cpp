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
		ll x, y, k;
		cin >> x >> y >> k;
		
		ll bagi = x-1;
		cout << (k*y+k-1+bagi-1)/bagi + k << "\n";
	}
	
    return 0;
}

