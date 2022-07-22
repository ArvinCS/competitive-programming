#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

ull gcd(ull a, ull b){
	if(a == 0) return b;
	return gcd(b%a, a);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	ull a,b;
	cin >> a >> b;
	
	cout << gcd(a,b) << "\n";
	
    return 0;
}

