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
	
	ll a, b, x, y;
	cin >> a >> b >> x >> y;
	
	while(x <= y){
		cout << x << "\n";
		x = a*x + b;
	}
	
    return 0;
}

