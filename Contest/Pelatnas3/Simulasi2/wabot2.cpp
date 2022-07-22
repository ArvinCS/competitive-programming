#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, t;
	cin >> n >> t;
	
	set<pair<int, int>> st;
	int l[t], r[t];
	vector<array<int, 3>> line;
	for(int x=0;x<t;x++){
		cin >> l[x] >> r[x];
		
		l[x]--; r[x]--;
		st.insert({l[x], r[x]});
		line.push_back({l[x], 1, x});
		line.push_back({r[x]+1, 0, x});
	}
	
	sort(line.begin(), line.end());
	
	bool active[t];
	fill(active, active+t, false);
	
	int lst = -1;
	
	bool mark[n];
	fill(mark, mark+n, false);
	
	int cnt = 0;
	for(auto p : line){
		int idx = p[2];
		if(active[idx]){ // going to remove
			for(int y=lst+1;y<p[0];y++){
				mark[y] = true;
			}
			lst = p[0]-1;
			cnt--;
		} else { // going to add
			if(cnt == 0){
				lst = max(p[0]-1, lst);
			}
			for(int y=lst+1;y<=p[0];y++){
				mark[y] = true;
			}
			lst = p[0];
			cnt++;
		}
		
		active[idx] ^= 1;
	}
	
	vector<pair<int, int>> w, z;
	int pos = 0;
	for(int x=0;x<n;x++){
		if(mark[x]){
			if(pos <= x-1){
				z.push_back({pos, x-1});
			}
			pos = x+1;
		}
	}
	if(pos <= n-1){
		z.push_back({pos, n-1});
	}
	
	pos = 0;
	for(int x=0;x<n;x++){
		if(!mark[x]){
			if(pos <= x-1){
				w.push_back({pos, x-1});
			}
			pos = x+1;
		}
	}
	if(pos <= n-1){
		w.push_back({pos, n-1});
	}
	
	vector<array<int, 3>> area;
	for(auto p : w){
		area.push_back({p.first, p.second, 0});
	}
	for(auto p : z){
		area.push_back({p.first, p.second, 1});
	}
	
	sort(area.begin(), area.end());
	
	vector<pair<int, int>> ans;
	int need = -1;
	for(auto p : area){
		if(p[2] == 0){
			if(p[0] == p[1]){
				if(need != -1){
					if(!st.count({need, p[0]})) ans.push_back({need, p[0]});
					need = -1;
				}
				continue;
			}
			
			int l = p[0]+1, r = p[1]-1;
			while(l <= r){
				if(!st.count({l, r})){
					ans.push_back({l, r});
				}
				l++; r--;
			}
			if((need != -1 ? need : p[0]) <= l-1){
				if(!st.count({(need != -1 ? need : p[0]), l-1})) ans.push_back({(need != -1 ? need : p[0]), l-1});
				need = -1;
			}
		} else {
			if(p[0] == p[1]){
				if(p[1] == z.back().second){
					continue;
				}
				
				assert(need == -1);
				
				need = p[0];
				continue;
			}
			
	//		cout << " = " << p[0] << " " << p[1] << "\n";
			int l = p[0]+(p[1] == z.back().second), r = p[1]-(p[1] == z.back().second);
			while(l <= r){
				if(!st.count({l, r})){
					ans.push_back({l, r});
				}
				l++; r--;
			}
			if(p[0] <= l-1){
				if(!st.count({p[0], l-1})) ans.push_back({p[0], l-1});
			}
		}
	}
	if(need != -1){
		if(!st.count({need, n-1})) ans.push_back({need, n-1});
	}
	
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	
	cout << ans.size() << "\n";
	for(auto p : ans){
		cout << p.first+1 << " " << p.second+1 << "\n";
	}
	return 0;
}
