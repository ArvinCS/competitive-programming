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
	
	pair<ll, ll> data[n];
	for(int x=0;x<n;x++){
		cin >> data[x].second >> data[x].first; // ingat ini a b ditukar
	}

	sort(data, data+n);
	
	ll ans = 0, cnt = 0;
	ll left = 0;
	for(int x=n-1;x>=0;x--){
		if(left > x) break;
		
		while(left < x && data[left].first <= cnt){
			ans += data[left].second;
			cnt += data[left].second;
			left++;
		}
		
		// case usaha kurangin jarak antara cnt dan b[x] sehingga makin hemat.
		while(left < x && cnt+data[x].second > data[left].first){
			if(cnt >= data[x].first) break;
					
			ll need = max(data[left].first-cnt, 0ll);
		
			ans += 2*need + data[left].second;
			cnt += need + data[left].second;
			
			data[x].second -= need;
			left++;
		}
		
		// case 1 (tengah jalan ada diskon)
		if(cnt+data[x].second > data[x].first){
			ll need = max(data[x].first-cnt, 0ll);
			
			ans += 2*need + (data[x].second-need);
			cnt += data[x].second;
		} else { // case 2 (tidak ada diskon)
			ans += 2*data[x].second;
			cnt += data[x].second;
		}
//		cout << x << " - " << ans << "\n";
	}
	
	cout << ans << "\n";
    return 0;
}

