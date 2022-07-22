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
	
	ll sum = 0;
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		sum += a[x];
	}
	
	vector<ll> w;
	for(ll x=2;x*x<=sum;x++){
		if(sum % x == 0){
			w.push_back(x);
			while(sum % x == 0){
				sum /= x;
			}
		}
	}
	if(sum > 1) w.push_back(sum);
	
	pair<ll, ll> suffix[n+1];
	ll ans = inf_ll;
	for(int x=0;x<w.size();x++){
		vector<pair<ll, int>> z;
		ll cur = 1;
		for(int y=0;y<n;y++){
			ll rem = a[y]%w[x];
			if(a[y]%w[x] > 0){
				z.push_back({cur, y});
				cur += rem;
			}
		}
		
		suffix[z.size()] = {0, 0};
		for(int y=z.size()-1;y>=0;y--){
			ll rem = a[z[y].second]%w[x];
			
			suffix[y] = suffix[y+1];
			suffix[y].first += z[y].second*rem;
			suffix[y].second += rem;
		}
		
		ll mid = (w[x]+1)/2;
		ll cnt = 0;
		int p1 = 0, p2 = 0, p3 = 0;
		for(int y=0;y*w[x]+mid<cur;y++){
			ll left = y*w[x]+1;
			ll right = (y+1)*w[x];
			
			while(p1 < z.size() && z[p1].first <= left) p1++;
			while(p2 < z.size() && z[p2].first <= y*w[x]+mid) p2++;
			while(p3 < z.size() && z[p3].first <= right) p3++;
			
			int idxLeft = p1-1, idxMid = p2-1, idxRight = p3-1;
			ll remLeft = (a[z[idxLeft].second]+z[idxLeft].first-1)%w[x], remRight = (a[z[idxRight].second]+z[idxRight].first-1)%w[x];
			ll excLeft = (a[z[idxLeft].second]-remLeft) % w[x], excRight = (a[z[idxRight].second] - remRight) % w[x];
			
			cnt += z[idxMid].second*(suffix[idxLeft].second - suffix[idxMid].second - excLeft) - (suffix[idxLeft].first - suffix[idxMid].first - excLeft*z[idxLeft].second);
			cnt += (suffix[idxMid+1].first - suffix[idxRight+1].first - remRight*z[idxRight].second) - z[idxMid].second*(suffix[idxMid+1].second - suffix[idxRight+1].second - remRight);
		}
		
//		cout << w[x] << " -> " << cnt << " " << sum%w[x] << "\n";
		ans = min(ans, cnt);
	}
	
	if(ans == inf_ll) ans = -1;
	cout << ans << "\n";
    return 0;
}

