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

	us t;
	cin >> t;
	
	while(t--){
		ll m, d, w;
		cin >> m >> d >> w;
		
		ll mn = w;
		for(ll x=1;x*x<=w;x++){
			if(w % x == 0){
				if((x*d) % w == x){
					mn = min(mn, x);
				}
				if(w/x != x){
					if((w/x*d) % w == w/x){
						mn = min(mn, w/x);
					}
				}
			}
		}
		
		ll cnt = min(m, d)/mn;
		ll tmp = cnt*(2*mn + (cnt-1)*mn)/2;
		cout << cnt * min(m, d) - tmp  << "\n";
	}

    return 0;
}

