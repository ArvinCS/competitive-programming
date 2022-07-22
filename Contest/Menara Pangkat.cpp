#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

const int maxN = 1e9;

int m;

ll pangkat(int x, int y){
	if(y == 0) return 1;
	ll tmp = pangkat(x, y/2);
	if(y % 2 == 0) return (tmp * tmp) % m;
	else (x * (tmp * tmp) % m) % m;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int a,b;
	cin >> a >> b >> m;
	
	cout << f(a,b) << "\n";
    return 0;
}

