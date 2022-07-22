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
	
	ll data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	ll mx[n];
	for(int x=n-1;x>=0;x--){
		if(data[x] > 0){
			if(data[x] >= (x+1 < n ? mx[x+1] : 0)){
				mx[x] = 0;
			} else {
				mx[x] = (x+1 < n ? mx[x+1] : 0);
			}
		} else {
			mx[x] = max(x+1 < n ? 0 : mx[x+1], -data[x]);
		}
	}
	
	vector<pair<ll, int>> v;
	for(int x=0;x<n;x++){
		if(mx[x] == 0){
			break;
		}
		v.push_back({mx[x], x});
	}
	
	sort(v.begin(), v.end());
	
	ll cnt = 0, ans = 0;
	for(int x=0;x<n;x++){
		if(data[x] >= 0){
			cnt += data[x];
			ans++;
		} else {
			if(cnt < data[x]) continue;
			
			auto it = lower_bound(v.begin(), v.end(), make_pair(cnt, x));
			auto it2 = lower_bound(v.begin(), v.end(), make_pair(cnt+data[x], x));
			
			if(it > it2){
				continue;
			} else {
				cnt += data[x];
				ans++;
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar
