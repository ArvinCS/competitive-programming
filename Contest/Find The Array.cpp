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
	
	us t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		
		ll total = 0;
		ll data[n];
		for(short x=0;x<n;x++){
			cin >> data[x];
			total += data[x];
		}
		
		for(short x=0;x<n;x++){
			if(x > 0) cout << " ";
			if(data[x] > 1){
				ll best = 2;
				for(ll y=4;y<=1e9;y*=2){
					if(abs(data[x]-y) < abs(data[x]-best)){
						best = y;
					}
				}
				cout << best;
			} else {
				cout << 1;
			}
		}
		cout << "\n";
	}
	
    return 0;
}

