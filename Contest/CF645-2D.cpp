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

	ll n, m;
	cin >> n >> m;
	
	ll data[2*n];
	for(int x=0;x<n;x++){
		cin >> data[x];
		data[n+x] = data[x];
	}
	n *= 2;
	
	ll day[n+1], sum[n+1];
	day[0] = sum[0] = 0;

	for(int x=0;x<n;x++){
		day[x+1] = data[x] + day[x];
		sum[x+1] = data[x]*(data[x]+1)/2 + sum[x];
	}
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		if(day[x+1] >= m){
			ll low = upper_bound(day, day+n+1, day[x+1]-m) - day;
			ll cnt = sum[x+1] - sum[low];
			ll days = day[x+1] - day[low];
			ll left = m-days;
			if(left >= 0){
				cnt += sum[low] - sum[low-1];
				cnt -= (data[low-1]-left)*(data[low-1]-left+1)/2;
			}
			ans = max(ans, cnt);
		}
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

