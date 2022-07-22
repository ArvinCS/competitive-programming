#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	vector<int> v;
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		v.push_back(a[x]);
	}
	
	array<int, 3> p[q];
	for(int x=0;x<q;x++){
		cin >> p[x][0] >> p[x][1];
		p[x][0]--; p[x][1]--;
		p[x][2] = x;
	}
	
	int sz = sqrt(n)+1;
	
	sort(p, p+q, [=](array<int, 3> p1, array<int, 3> p2) -> bool {
		if(p1[0]/sz == p2[0]/sz){
			return (p1[0]/sz % 2 == 0 ? p1[1] < p2[1] : p1[1] > p2[1]);
		}
		return p1[0] < p2[0];
	});
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	for(int x=0;x<n;x++){
		a[x] = lower_bound(v.begin(), v.end(), a[x]) - v.begin();
	}
	
	int freq[v.size()], id[n+1];
	pair<int, int> lazy[n+1];
	fill(freq, freq+v.size(), 0);
	fill(id, id+n+1, -1);
	fill(lazy, lazy+n+1, make_pair(0, 0));
	
	stack<int> st;
	for(int x=n-1;x>=0;x--){
		st.push(x);
	}
	
	auto add = [&](int val) -> void {
		if(freq[val] > 0){
			lazy[id[freq[val]]].first--;
			
			if(lazy[id[freq[val]]].first == 0){
				st.push(id[freq[val]]);
				id[freq[val]] = -1;
			}
		}
		
		freq[val]++;
		
		if(id[freq[val]] == -1){
			id[freq[val]] = st.top();
			lazy[id[freq[val]]].second = freq[val];
			st.pop();
		}
		
		lazy[id[freq[val]]].first++;
	};
	auto remove = [&](int val) -> void {
		lazy[id[freq[val]]].first--;
		
		if(lazy[id[freq[val]]].first == 0){
			st.push(id[freq[val]]);
			id[freq[val]] = -1;
		}
		
		freq[val]--;
		
		if(freq[val] > 0){
			if(id[freq[val]] == -1){
				id[freq[val]] = st.top();
				lazy[id[freq[val]]].second = freq[val];
				st.pop();
			}
			
			lazy[id[freq[val]]].first++;
		}
	};
	
	ll ans[q];
	int curL = 0, curR = 0;
	for(int x=0;x<q;x++){ // [L, R)
		int l = p[x][0], r = p[x][1], idx = p[x][2];
		
		while(curL > l){
			curL--;
			add(a[curL]);
		}
		while(curR <= r){
			add(a[curR]);
			curR++;
		}
		
		while(curL < l){
			remove(a[curL]);
			curL++;
		}
		while(curR > r+1){
			curR--;
			remove(a[curR]);
		}
		
		vector<pair<int, int>> v;
		for(int y=0;y<min(2000, n);y++){
			if(lazy[y].first > 0){
				v.push_back({lazy[y].second, lazy[y].first});
			}
		}
		
		sort(v.rbegin(), v.rend());
		
		ll cnt = 1;
		ans[idx] = 0;
		for(int y=0;y<v.size();y++){
			ans[idx] += ((cnt+v[y].second-1)*(cnt+v[y].second)/2 - cnt*(cnt-1)/2)*1ll*v[y].first;
			cnt += v[y].second;
		}
	}
	
	for(int x=0;x<q;x++){
		cout << ans[x] << "\n";
	}
    return 0;
}

