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
	
	int a, b, c, x;
	ll ans = 0;
	
	cin >> a >> b >> c >> x;
	
	int z = x;
	while(true){
		z = (a*z+b)%c;
		ans++;
		if(z == x) break;
	}
	
	cout << ans << "\n";
    return 0;
}

