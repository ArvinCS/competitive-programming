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


ull pow(ull x, ull y, ull z){
	if(y==1) return x % z;
	ull tmp = (pow(x, y/2, z) * pow(x, y/2, z)) % z;
	if(y&1) return (tmp * x) % z;
	else return tmp;
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ull n, m;
	cin >> n >> m;
	
	cout << (pow(10,n,m*m)/m) % m << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

