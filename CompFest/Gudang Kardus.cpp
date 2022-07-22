#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

#define phi 3.14
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ui r, s;
	cin >> r >> s;
	
	cout << (r*r) / (s*s) << "\n";
    return 0;
}

