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
		ll n;
		cin >> n;
		
		if(n <= 6){
			cout << "15\n";
			continue;
		}
		
		ll remain = n%6;
		if(remain != 0){
			n -= 6+remain;
		}
		
		ll ans = (n/6) * 15;
		if(remain > 0){
			if(remain <= 2){
				ans += 20;
			} else if(remain <= 4){
				ans += 25;
			} else {
				ans += 30;
			}
		}
		
		cout << ans << "\n";
	}

    return 0;
}

