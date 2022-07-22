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

void solve(){
	short n;
	cin >> n;
	
	for(short a=0;a<=334;a++){
		if(a * 3 > n) break;
		for(short b=0;b<=201;b++){
			short tmp = n - (a * 3) - (b * 5);
			if(tmp >= 0 && tmp % 7 == 0){
				cout << a << " " << b << " " << (tmp/7) << "\n";
				return;
			} else {
				continue;
			}
		}
	}
	cout << "-1\n";
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short t;
	cin >> t;
	
	while(t--){
		solve();
	}
	
    return 0;
}

