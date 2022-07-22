#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	vector<array<int, 3>> v;
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
		v.push_back({p[x].first, 0, x});
		v.push_back({p[x].second, 1, x});
	}
	
	sort(v.begin(), v.end());
	
	pair<int, int> d[q];
	vector<int> s[n], e[n];
	for(int x=0;x<q;x++){
		cin >> d[x].first >> d[x].second;
		d[x].first--; d[x].second--;
	}
	
	for(int x=0;x<q;x++){
		s[d[x].first].push_back(x);
		e[d[x].second].push_back(x);
	}
	
	bool active[n], active2[q];
	fill(active, active+n, false);
	fill(active2, active2+q, false);
	
	int ans[q];
	fill(ans, ans+q, 1e9);
	
	int mx = 0;
	multiset<int> st;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for(int x=0;x<v.size();x++){
		if(!active[v[x][2]]){
			mx = max(mx, p[v[x][2]].second);
			
			for(auto idx : s[v[x][2]]){
				ans[idx] = 0;
				if(d[idx].second != v[x][2]){
					active2[idx] = true;
					pq.push({p[v[x][2]].second, idx});
				}
			}
			for(auto idx : e[v[x][2]]){
				if(!active2[idx]) continue;
//				cout << idx << " " << ans[idx] << " " << v[x][0] << "\n";
				active2[idx] = false;
				
				auto it = st.lower_bound(v[x][0]);
//				cout << *it << " -\n";
				if(it != st.end() && *it <= p[v[x][2]].second){
					ans[idx]++;
				} else {
					ans[idx] = 1e9;
				}
			}
			
			st.insert(p[v[x][2]].second);
		} else {
			st.erase(st.find(v[x][0]));
		}
		
		active[v[x][2]] ^= 1;
		
		if(x+1 < v.size() && v[x][0] == v[x+1][0]) continue;
		
		while(!pq.empty() && pq.top().first <= v[x][0]){
			pair<int, int> cur = pq.top();
			pq.pop();
			
			if(!active2[cur.second]) continue;
			
//			cout << active[d[cur.second].second] << " " << v[x][0] << " " << mx << " " << cur.first << " " << cur.second << "\n";
			ans[cur.second]++;
			
			if(mx <= v[x][0]){
				ans[cur.second] = 1e9;
				active2[cur.second] = false;
				continue;
			}
			
			if(!active[d[cur.second].second]) pq.push({mx, cur.second});
		}
	}
	
	for(int x=0;x<q;x++){
		if(p[d[x].first].second > p[d[x].second].second){
			ans[x] = 1e9;
		}
	}
	
	for(int x=0;x<q;x++){
		if(ans[x] > n){
			cout << "impossible\n";
			continue;
		}
		
		cout << ans[x] << "\n";
	}
    return 0;
}

