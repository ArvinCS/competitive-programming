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

int a[305],b[305],w[305],n,m;
DSU dsu;

int solve(ll val){
	int ans = 0;
	
	dsu.reset();
	
	vector<pair<int,int>> v;
	for(int x=0;x<m;x++){
		v.push_back({abs(val-w[x]), x});
	}
	sort(v.begin(), v.end());
	for(int x=0;x<m;x++){
		if(dsu.merge(a[v[x].second], b[v[x].second])){
			if(val == 6) cout << v[x].second << " --\n";
			ans+=v[x].first;
		}
	}
	cout << "=\n";
	return ans;
}

int main(){
	cin>>n>>m;
	
	for(int x=0;x<m;x++){
		cin >> a[x] >> b[x] >> w[x];
		
		a[x]--;b[x]--;
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
		cout << solve(last) << "\n";
	}
	for(int x=p;x<k;x++){
		last = (last*a+b)%c;
		
		ans ^= solve(last);
		cout << last << " " << solve(last) << "\n";
	}
	cout << ans << "\n";
	return 0;
}
