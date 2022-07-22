#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const int maxN = 2e5 + 5;

ll pw[maxN];

ll powmod(ll x, ll y){
	ll ans = 1;
	
	x %= mod;
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x * x) % mod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	pw[0] = 1;
	for(int x=1;x<maxN;x++){
		pw[x] = (3 * pw[x-1]) % mod;
	}
	
	int n, m;
	cin >> n;
	
	ll sum = 0;
	pair<int, ll> a[n];
	for(int x=0;x<n;x++){
		cin >> a[x].first >> a[x].second;
		sum += a[x].second;
	}
	
	cin >> m;
	
	int last = -1;
	ll t = 0;
	ll l = 0, r = 0, cnt = 0;
	vector<pair<int, ll>> w;
	pair<int, ll> b[m];
	for(int x=0;x<m;x++){
		cin >> b[x].first >> b[x].second;
	}
	
	for(int x=0;x<m;x++){
		if(last != b[x].first && last >= 0){
			w.push_back({last, cnt});
			cnt = 0;
		}
		
		cnt += b[x].second;
		last = b[x].first;
	}
	
	w.push_back({last, cnt});
	cnt = 0;
	
	vector<pair<int, ll>> v;
	last = -1;
	sum = 0;
	for(int x=0;x<n;x++){
		if(last != a[x].first && last >= 0){
			v.push_back({last, sum});
			sum = 0;
		}
		
		sum += a[x].second;
		last = a[x].first;
	}
	
	v.push_back({last, sum});
	sum = 0;
	
	if(w.size() > 1){
		ll hash[v.size()];
		for(int x=0;x<v.size();x++){
			if(x > 0) hash[x] = hash[x-1];
			else hash[x] = 0;
			
			hash[x] *= powmod(2, v[x].second);
			hash[x] %= mod;
			hash[x] += (powmod(2, v[x].second)-1) * v[x].first;
			hash[x] %= mod;
		}
		
		ll prefix[v.size()];
		for(int x=0;x<v.size();x++){
			if(x > 0) prefix[x] = prefix[x-1];
			else prefix[x] = 0;
			
			prefix[x] += v[x].second;
		}
		
		ll t = 0, length = 0;
		for(int x=0;x<w.size();x++) cnt += w[x].second;
		for(int x=1;x+1<w.size();x++){
			t *= powmod(2, w[x].second);
			t %= mod;
			t += (powmod(2, w[x].second)-1) * w[x].first;
			t %= mod;
			length += w[x].second;
		}
		
		ll ans = 0;
		for(int x=1;x<v.size();x++){
			int left = 0, right = x-1, bound = -1;
			while(left <= right){
				int mid = (left+right) >> 1;
				
				ll length = prefix[x-1] - (mid > 0 ? prefix[mid-1] : 0);
				if(length >= cnt-w.back().second){
					left = mid+1;
					bound = max(bound, mid);
				} else {
					right = mid-1;
				}
			}
			
			if(bound == -1) continue;
			
			ll val = ((x > 0 ? hash[x-1] : 0) - hash[bound] * powmod(2, length) % mod + mod) % mod;
			if(v[bound].second >= w.front().second && v[x].second >= w.back().second && v[bound].first == w.front().first && v[x].first == w.back().first && val == t){
				ans++;
			}
		}
		
		cout << ans << "\n";
	} else {
		ll ans = 0;
		for(int x=0;x<v.size();x++){
			if(v[x].first == w[0].first && v[x].second >= w[0].second){
				ans += v[x].second-w[0].second+1;
			}
		}
		cout << ans << "\n";
	}
	
    return 0;
}

