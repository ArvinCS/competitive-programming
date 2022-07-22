#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 55;

struct DSU {
	int parent[maxN],sz[maxN];
	
	void reset(){
		for(int x=0;x<maxN;x++){
			parent[x] = x;
			sz[x] = 1;
		}
	}
	
	int getParent(int x){
		if(parent[x] == x) return x;
		return parent[x] = getParent(parent[x]);
	}
	
	bool merge(int x,int y){
		int a = getParent(x);
		int b = getParent(y);
		
		if(a!=b){
			if(sz[a]<sz[b])swap(a,b);
			
			parent[b] = a;
			sz[a] += sz[b];
			return true;
		}
		return false;
	}
};

int a[305],b[305],n,m;
pair<int, int> w[305];
vector<int> v[305];
DSU dsu;
map<int, int> mp;

int solve(int val){
	if(mp.find(val) != mp.end()) return mp[val];
	
	int ans = 0;
	
	dsu.reset();
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	auto itr = lower_bound(w, w+m, make_pair(val, -100));
	auto itl = w+m;
	
	if(itr != w){
		itl =  itr-1;
	}
	if(itr != w+m && !v[(*itr).second].empty()){
		for(auto idx : v[(*itr).second]){
			pq.push({abs(val-w[idx].first), w[idx].second});
		}
	}
	if(itl != w+m && !v[(*itl).second].empty()){
		for(auto idx : v[(*itl).second]){
			pq.push({abs(val-w[idx].first), w[idx].second});
		}
	}
	
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		
		if(dsu.merge(a[p.second], b[p.second])){
			ans += p.first;
		}
	}
	return mp[val] = ans;
}

int main(){
	cin>>n>>m;
	
	for(int x=0;x<m;x++){
		cin >> a[x] >> b[x] >> w[x].first;
		
		a[x]--; b[x]--;
		w[x].second = x;
	}
	
	sort(w, w+m);
	
	for(int x=0;x<m;x++){
		dsu.reset();
		dsu.merge(a[w[x].second], b[w[x].second]);	
		v[w[x].second].push_back(x);
		
		int l = x-1, r = x+1;
		while(l >= 0 || r < m){
			if(l >= 0 && r < m){
				if(w[x].first-w[l].first <= w[r].first-w[x].first){
					if(dsu.merge(a[w[l].second], b[w[l].second])){
						v[w[x].second].push_back(l);
					}
					l--;
				} else {
					if(dsu.merge(a[w[r].second], b[w[r].second])){
						v[w[x].second].push_back(r);
					}
					r++;
				}
			} else if(l >= 0){
				if(dsu.merge(a[w[l].second], b[w[l].second])){
					v[w[x].second].push_back(l);
				}
				l--;
			} else {
				if(dsu.merge(a[w[r].second], b[w[r].second])){
					v[w[x].second].push_back(r);	
				}
				r++;
			}
		}
	}
	
	ll p,k,a,b,c;
	cin >> p >> k >> a >> b >> c;
	
	int ans = 0;
	ll last = 0;
	for(int x=0;x<p;x++){
		ll val;
		cin >> val;
		
		last = val;
		ans ^= solve(val);
	}
	for(int x=p;x<k;x++){
		last = (last*a+b)%c;
		
		ans ^= solve(last);
	}
	cout << ans << "\n";
	return 0;
}
