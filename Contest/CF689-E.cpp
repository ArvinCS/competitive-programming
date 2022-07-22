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

	ll k, l, r, t, x, y;
	cin >> k >> l >> r >> t >> x >> y;
	
	ll diff = abs(x-y);
	
	if(x > y){
		if(k+y <= r){
			if((k+y-(l+x))/diff + 1 >= t){
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		} else {
			if((k-(l+x))/diff + 1 >= t){
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
	} else if(x == y){
		if(k+y <= r){
			if(k+y-x >= l){
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		} else {
			if(k-x >= l){
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
	} else {
		ll cnt = (k-l)/x;
		k -= x*cnt;
		
		diff = y%x;
		
		ll tmp = (r-y-k)/diff + 1;
		if(diff == 0){
			if(k+y <= r){
				cout << "Yes\n";
			} else {
				if(cnt >= t){
					cout << "Yes\n";
				} else {
					cout << "No\n";
				}
			}
		} else if((k-l+tmp*diff) >= x || tmp*(y/x) + cnt >= t){ // cycle or not
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

    return 0;
}

