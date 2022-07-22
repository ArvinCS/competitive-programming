#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

int m;
pair<ll, int> table[maxN];
pair<int, ll> p[maxN];
vector<int> v[maxN];

void solve(int l, int r, int optL, int optR){
	if(l > r) return;
		
	int mid = (l+r) >> 1;
	ll val = -1e18;
	int idx = -1, cnt = 0;
	ll mx[m], cost = 0;
	fill(mx, mx+m, 0);
	
	for(int x=min(mid, optR);x>=optL;x--){
		if(mx[p[x].first] < p[x].second){
			if(mx[p[x].first] == 0) cnt++;
			cost += p[x].second-mx[p[x].first];
			mx[p[x].first] = p[x].second;
		}
		if(cnt != m) continue;
		ll cur = (x > 0 ? table[x-1].first : 0) + cost;
		cout << mid << " -> " << x << " " << cur << "\n";
		
		if(cur >= val){
			val = cur;
			idx = x;
		}
	}
	
	cout << mid << " [" << l << ", " << r << "] " << optL << " " << optR << "\n";
	table[mid] = {val, idx};
	
	solve(l, mid-1, optL, idx);
	solve(mid+1, r, idx, optR);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n >> m;
	
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
		p[x].first--;
	}
	
	fill(table, table+n, make_pair(-1e18, -1));
	solve(0, n-1, 0, n-1);
	
	pair<ll, int> mx[m];
	
	pair<ll, int> best = {-1e18, -1};
	for(int x=n-1;x>=0;x--){
		best = max(best, {table[x].first, x});
	}
	
	string ans(n, 'X');
	fill(mx, mx+m, make_pair(0, n));
	
	int pos = best.second;
	while(pos >= 0){
		int l = table[pos].second;
		
		for(int x=l;x<=pos;x++){
			if(mx[p[x].first].second > pos){
				ans[x] = 'O';
				mx[p[x].first] = {p[x].second, x};
			} else if(mx[p[x].first].first < p[x].second){
				ans[mx[p[x].first].second] = 'X';
				ans[x] = 'O';
				mx[p[x].first] = {p[x].second, x};
			}
		}
		pos = l-1;
	}
	
	cout << ans << "\n";
    return 0;
}
