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
		ll n, k;
		cin >> n >> k;
		
		ll data[n], sum = 0;
		for(ll x=0;x<n;x++){
			cin >> data[x];
			sum += data[x];
		}
		
		ll left = 1, right = sum/k, pos = 0;
		while(left <= right){
			ll mid = (left+right) >> 1;
			
			ll cnt = 0, tmp = 0;
			for(ll x=0;x<n;x++){
				if(tmp+data[x] < mid) tmp = 0;
				cnt += (tmp+data[x])/mid;
				tmp = (tmp+data[x])%mid;
			}
			
			if(cnt >= k){
				left = mid+1;
				pos = mid;
			} else {
				right = mid-1;
			}
		}
		
		cout << pos*k << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

