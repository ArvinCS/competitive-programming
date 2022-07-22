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
	
	int t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		
		ll cur = 1;
		while(cur*4 <= n){
			cur *= 4;
		}
		
		ll pos = (n-cur)/3 + 1;
		ll a = pos+cur-1;
		ll b = 0;
		
		for(int i=0;i<60;i+=2){
			int cnt = 0;
			if(a&(1ll << i)) cnt++;
			if(a&(1ll << (i+1))) cnt += 2;
			
			if(cnt == 1) b += (1ll << (i+1));
			else if(cnt == 2) b += (1ll << i) + (1ll << (i+1));
			else if(cnt == 3) b += (1ll << i);
		}
		
		if(n % 3 == 1){
			cout << a << "\n";
		} else if(n % 3 == 2){
			cout << b << "\n";
		} else {
			cout << (a^b) << "\n";
		}
	}

	// a^b^c = 0
	// a = b^c
	
    return 0;
}

