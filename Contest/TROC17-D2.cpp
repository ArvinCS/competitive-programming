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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, k;
	cin >> n >> k;
	
	int op[n];
	fill(op, op+n, 0);
	
	for(int x=0;x<k;x++){
		int a, b;
		cin >> a >> b;
		
		b--;
		op[b] = (a == 1 ? -1 : 1);
	}
	
	ll ans = 1;
	int low = 0, high = n-1;
	for(int x=n-1;x>=0;x--){
		if(op[x] != 0){
			if(op[x] == 1){
				ans *= (n-high-x);
				high--;
			} else {
				ans *= (n-low-x);
				low++;
			}
			ans %= smod;
		}
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

