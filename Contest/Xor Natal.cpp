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

int mul(int a, int b){
	int ans = 0;
	a %= smod;
	
	while(b > 0){
		if(b & 1) ans = (ans+a) % smod;
		
		a = (2*a) % smod;
		b >>= 1;
	}
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	short data[n];
	for(int x=0;x<n;x++) cin >> data[x];
	
	int ans = 1;
	for(int x=0;x<n;x++){
		for(int y=x+1;y<n;y++){
			if(ans == 0) break;
			ans = mul(ans, data[x]^data[y]);
		}
	}
	
//	cout << (3&6&5) << "\n";
	cout << ans << "\n";
    return 0;
}

