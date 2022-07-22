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

int leftBit(int n){
	for(int x=31;x>=0;x--){
		if(n&(1 << x)){
			return x;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int ans = 0;
		for(int x=leftBit(n)-1;x>=0;x--){
			ans |= (1<<x);
		}
		cout << ans << "\n";	
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

