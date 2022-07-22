#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

ui gcd(ui a, ui b){
	if(a == 0) return b;
	return gcd(b%a, a);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n;
	ui a, b;
	
	cin >> n >> a >> b;
	
	ll ans = n/a + n/b - n/((a*1ll*b)/gcd(a,b));
	cout << ans << "\n";
	
    return 0;
}

