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

ull fac[21];

ull comb(int a, int b){
	return fac[a]/(fac[a-b] * fac[b]);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fac[0] = fac[1] = 1;
	for(short x=2;x<=20;x++){
		fac[x] = x * fac[x-1];
	}
	
	ull n;
	cin >> n;
	
	cout << fac[n-1]/(n/2) << "\n";
	
	
    return 0;
}

