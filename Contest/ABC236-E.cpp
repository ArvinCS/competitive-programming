#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool customSort(tuple<ll, ll, ll> a, tuple<ll, ll, ll> b){
	if(get<0>(a)*get<1>(b) == get<0>(b)*get<1>(a)){
		return get<2>(a) > get<2>(b);
	}
	return get<0>(a)*get<1>(b) > get<0>(b)*get<1>(a);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, function<bool(tuple<ll, ll, ll>, tuple<ll, ll, ll>)>> pq(customSort);
	pq.push(make_tuple(a[0], 1, 0)); 
	pq.push(make_tuple(a[1], 1, 1)); 
	
	pair<ll, ll> ans1 = {0, 1};
	while(!pq.empty()){
		tuple<ll, ll, ll> t = pq.top();
		pq.pop();
		
		int idx = get<2>(t);
		if(idx >= n-2){
			if(ans1.first*get<1>(t) < get<0>(t)*ans1.second){
				ans1 = {get<0>(t), get<1>(t)};
			}
		}
		
		if(idx+1 < n){
			pq.push(make_tuple(get<0>(t)+a[idx+1], get<1>(t)+1, idx+1));
		}
		if(idx+2 < n){
			pq.push(make_tuple(get<0>(t)+a[idx+2], get<1>(t)+1, idx+2));
		}
	}
	
	cout << fixed << setprecision(6) << ans1.first*1.0/ans1.second << "\n";
	
	bool exist[n];
	fill(exist, exist+n, true);
	
	vector<pair<ll, int>> v;
	for(int x=0;x<n;x++){
		v.push_back({a[x], x});
	}
	
	sort(v.begin(), v.end());
	
	vector<ll> w;
	
	ll ans2 = 0;
	int sz = n, cnt = 0;
	for(int x=0;x<v.size();x++){
		if((v[x].second == 0 || exist[v[x].second-1]) && (v[x].second == n-1 || exist[v[x].second+1])){
			exist[v[x].second] = false;
			sz--;
			
			if((sz+1)/2 > cnt){
				ans2 = max(ans2, v[x+(sz+1)/2-cnt].first);
			} else {
				ans2 = max(ans2, w[(sz+1)/2-1]);
			}
		} else {
			cnt++;
			w.push_back(v[x].first);
		}
	}
	
	cout << ans2 << "\n";
    return 0;
}

