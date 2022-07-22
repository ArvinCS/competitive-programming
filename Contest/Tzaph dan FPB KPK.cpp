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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	ull fpb, kpk;
	cin >> fpb >> kpk;

	if(kpk % fpb != 0){
		cout << "-1 -1\n";
		return 0;
	}

	kpk /= fpb;
	
	ull total = inf_ll, a = -1, b = -1;

	for(ull x=1;x*x<=kpk;x++){
		if(kpk % x == 0){
			if(kpk/x + x < total && __gcd(kpk/x, x) == 1){
				total = kpk/x + x;
				a = kpk/x;
				b = x;
			}
		}
	}
	cout << a*fpb << " " << b*fpb << "\n";
    return 0;
}
