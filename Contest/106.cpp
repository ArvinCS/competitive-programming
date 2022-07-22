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
	
	ull n;
	cin >> n;
	
	ull a = 3, pangkat3 = 1;
	while(a < n){
		ull b = n-a, pangkat5 = 0;
		if(b > 1 && b%5 == 0){
			while(b % 5 == 0){
				b /= 5;
				pangkat5++;
			}
			if(b == 1){
				cout << pangkat3 << " " << pangkat5 << "\n";
				return 0;
			}
		}
		a *= 3;
		pangkat3++;
	}
	cout << "-1\n";
    return 0;
}

