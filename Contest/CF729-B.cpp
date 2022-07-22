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
		ll n, a, b;
		cin >> n >> a >> b;
		
		if(n == 1){
			cout << "Yes\n";
			continue;
		}
		if(b == 1){
			cout << "Yes\n";
			continue;
		}
		if(a == 1){
			if((n-1)%b == 0){
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
			continue;
		}
		
		bool possible = false;
		for(ll x=1;x<=n;x*=a){
			if((n-x)%b == 0){
				possible = true;
				break;
			}
		}
		
		if(possible) cout << "Yes\n";
		else cout << "No\n";
	}
	
    return 0;
}

