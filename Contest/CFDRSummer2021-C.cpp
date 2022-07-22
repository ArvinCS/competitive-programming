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
	
	int n;
	cin >> n;
	
	ll c[n];
	for(int x=0;x<n;x++){
		cin >> c[x];
	}
	
	ll ans = 0;
	for(int x=0;x<n;x+=2){		
		ll sum = 1;
		ll cnt1 = 1;
		for(int y=x+1;y<n;y++){
			if(c[x]-cnt1 < 0) break;
			
			if(y % 2 == 1){
				if(sum >= 0){
					ans += max(min(c[x]-cnt1+1, c[y]-sum+1), 0ll);
				} else {
					cnt1 += abs(sum);
					if(c[x]-cnt1 < 0) break;
					
					ans += max(min(c[x]-cnt1+1, c[y]), 0ll);
					sum = 0;
				}
			} else {
				if(sum < 0){
					cnt1 += abs(sum);
					sum = 0;
				}
			}
			
			if(y % 2 == 0){
				sum += c[y];
			} else {
				sum -= c[y];
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

