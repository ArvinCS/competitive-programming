#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

#define mod 1000000007

ull solve(int n){
	if(n == 1) return 2;
	ull tmp = solve(n/2) % mod;
	if(n % 2 == 0) return (tmp * tmp) % mod;
	else return (tmp * (tmp * 2) % mod) % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ull n;
	cin >> n;
	
	cout << (solve(n) - 1) % mod << "\n";
	
    return 0;
}

