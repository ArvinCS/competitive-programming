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
	
	ull n, m;
	cin >> n >> m;
	
	ull ans = 2 * ((n-2) * (n+1) + (m-2) * (m+1));
	cout << ans << "\n";
    return 0;
}

