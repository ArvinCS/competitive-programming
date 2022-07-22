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
	
	ll n, m;
	cin >> n >> m;
	
	if(n >= m && n <= m*5){
		ll mn = max(n - (m * 4), 0ll);
		ll mx = max(n-m, 0ll)/4;
		
		cout << mn << " " << mx << "\n";
	} else {
		cout << "-1 -1\n";
	}
	
    return 0;
}

