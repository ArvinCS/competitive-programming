#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll k, l;
	cin >> k >> l;
	
	int n;
	cin >> n;
	
	vector<ll> v[2];
	for(int x=0;x<n;x++){
		int a, b;
		cin >> a >> b;
		
		v[(b == 1)].push_back(a);
	}
	
	int m;
	cin >> m;
	
	pair<ll, ll> p[m]; // remember this one is swapped
	for(int x=0;x<m;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	for(int i=0;i<2;i++){
		if(!v[i].empty()) sort(v[i].begin(), v[i].end());
	}
	
	pair<ll, int> mn[m];
	for(int x=0;x<m;x++){
		ll dist = 1e9;
		
		auto it = lower_bound(v[1].begin(), v[1].end(), p[x].first+1);
		
		if(it != v[1].begin()){
			it--;
			dist = min(dist, p[x].first-*it);
		}
		
		it = lower_bound(v[0].begin(), v[0].end(), p[x].first);
		
		if(it != v[0].end()){
			dist = min(dist, *it-p[x].first);
		}
		
		mn[x] = {dist, x};
	}
	
	sort(mn, mn+m);
	
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	
	ll ans = 0, cur = l;
	for(int x=0;x<m;x++){
		if(mn[x].first > cur){
			ll need = max(0ll, min(k-cur, mn[x].first-cur));
			
			if(pq.size() < need){
				break;
			}
			
			for(ll y=0;y<need;y++){				
				ans += pq.top();
				pq.pop();
				cur++;
			}
						
			pq.push(p[mn[x].second].second);
		} else {
			pq.push(p[mn[x].second].second);
		}
	}
	
	ll need = max(0ll, k-cur);
	if(pq.size() < need){
		cout << "-1\n";
		return 0;
	}
	
	for(ll y=0;y<need;y++){
		ans += pq.top();
		pq.pop();
	}
			
	cout << ans << "\n";
    return 0;
}

