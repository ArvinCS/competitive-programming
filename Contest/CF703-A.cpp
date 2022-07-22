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
	
	int t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		
		ll data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		for(int x=0;x<n-1;x++){
			ll tmp = max(data[x]-x, 0ll);
			data[x+1] += tmp;
			data[x] -= tmp;
		}
		
		bool valid = true;
		for(int x=1;x<n;x++){
			if(data[x-1] >= data[x]){
				valid = false;
				break;
			}
		}
		
		if(valid){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

