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
	ll m, k;
	cin >> k >> n >> m;
	
	ll data[k];
	for(int x=0;x<k;x++){
		cin >> data[x];
	}
		
	vector<ll> v;
	for(int x=0;x<k;x++){
		v.push_back(data[x]*m);
	}
	
	ll left = 1, right = m*n, best = -1;
	while(left <= right){
		ll mid = (left+right)>>1;
		ll cur = m;
		bool possible = (cur >= 0);
		
		ll cost[k];
		for(int x=0;x<k;x++){
			if(v[x] <= mid){
				cost[x] = 0;
				continue;
			}
			
			ll need = mid+v[x], need2 = -mid+v[x];
			if((need+n-1)/n > cur && (need2 < 0 || (need2+n-1)/n > cur)){
				possible = false;
				break;
			}
			if(need2 < 0 || (need2+n-1)/n > cur || need2 > need){
				cur -= (need+n-1)/n;
				cost[x] = (need+n-1)/n;
			} else {
				cur -= (need2+n-1)/n;
				cost[x] = (need2+n-1)/n;
			}
		}
		
		for(int x=0;x<k;x++){
			if(cur == 0) break;
			ll res = cost[x]*n - v[x];
			if(res <= 0){
				cost[x] += min((mid-res)/n, cur);
				cur -= min((mid-res)/n, cur);
			} else {
				if(res < mid){
					cost[x] += min((mid-res)/n, cur);
					cur -= min((mid-res)/n, cur);
				}
			}
		}
		
		if(cur > 0) possible = false;
		if(possible){
			right = mid-1;
			best = mid;
		} else {
			left = mid+1;
		}
	}
	
	ll ans[k], cur = m;
	for(int x=0;x<k;x++){
		if(v[x] <= best){
			ans[x] = 0;
			continue;
		}
		
		ll need = best+v[x], need2 = -best+v[x];
		if(need2 < 0 || (need2+n-1)/n > cur || need2 > need){
			cur -= (need+n-1)/n;
			ans[x] = (need+n-1)/n;
		} else {
			cur -= (need2+n-1)/n;
			ans[x] = (need2+n-1)/n;
		}
	}
	
	for(int x=0;x<k;x++){
		if(cur == 0) break;
		ll res = ans[x]*n - v[x];
		if(res <= 0){
			ans[x] += min((best-res)/n, cur);
			cur -= min((best-res)/n, cur);
		} else {
			if(res < best){
				ans[x] += min((best-res)/n, cur);
				cur -= min((best-res)/n, cur);
			}
		}
	}
	
	for(int x=0;x<k;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

