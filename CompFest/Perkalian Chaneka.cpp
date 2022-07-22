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
	
	ull a, b;
	cin >> a >> b;
	
	if(a % 11 == 0) cout << a / 11 * b << "\n";
	else cout << b / 11 * a << "\n";
    return 0;
}

