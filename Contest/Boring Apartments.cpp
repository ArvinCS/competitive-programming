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

short len(short x){
	short ans = 0;
	while(x > 0){
		x /= 10;
		ans++;
	}
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		short x;
		cin >> x;
		
		int digit = x%10, panjang = len(x);
		
		int ans = (digit-1) * 10 + (panjang * (panjang+1))/2;
		
		cout << ans << "\n";
	}
	
    return 0;
}

