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
	
	int n;
	cin >> n;
	
	int ans = 0;
	for(int x=1;x<=n;x++){
		bool decimal = true, octal = true;
		
		int cur = x;
		while(cur > 0){
			if(cur % 10 == 7){
				decimal = false;
				break;
			}
			cur /= 10;
		}	
		cur = x;
		while(cur > 0){
			if(cur % 8 == 7){
				octal = false;
				break;
			}
			cur /= 8;
		}
		
		if(decimal && octal) ans++;
	}
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

