#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5e4 + 5;
const int sz = 500;

ll prefix[maxN];
int l[maxN], a[maxN], idx[maxN], cnt[maxN], L[maxN][sz+5], R[maxN][sz+5];
vector<pair<int, ll>> v[maxN];
array<int, 3> que[maxN];
vector<array<int, 3>> w[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, q;
	cin >> n >> m >> q;
	
	fill(prefix, prefix+n, 0);
	
	for(int x=0;x<n;x++){
		cin >> l[x];
		l[x]--;
	}
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	fill(cnt, cnt+m, 0);
	
	for(int x=0;x<q;x++){
		cin >> que[x][0];
		
		for(int y=1;y<(que[x][0] == 1 ? 3 : 2);y++){
			cin >> que[x][y];
		}
	}
	
	vector<int> pending;
	for(int x=0;x<q;x++){
		int t = que[x][0];
		
		if(pending.size() >= sz){
			for(auto idx : pending) cnt[idx] = 0;
			pending.clear();
		}
		
		if(t == 1){
			int l = que[x][1], r = que[x][2];
			
			l--; r--;
			
			for(auto idx : pending){
				w[r+1].push_back({idx, x, 1});
				w[l].push_back({idx, x, 0});
			}
		} else {
			int p = que[x][1];
			
			p--;
			
			if(cnt[p] == 0){
				pending.push_back(p);
			}
			cnt[p]++;
		}
	}
	
//	fill(cnt, cnt+m, 0);
	for(int x=0;x<m;x++){
		cnt[x] = 0;
		v[x].clear();
	}
	pending.clear();
	for(int x=0;x<n;x++){
		idx[x] = v[l[x]].size();
		v[l[x]].push_back({x, a[x]+(v[l[x]].empty() ? 0 : v[l[x]].back().second)});
		prefix[x] = a[x] + (x > 0 ? prefix[x-1] : 0);
	}
	
	int cur_idxL[q], cur_idxR[q];
	fill(cur_idxL, cur_idxL+q, 0);
	fill(cur_idxR, cur_idxR+q, 0);
	for(auto p : w[n]){
		if(p[2] == 0){
			L[p[1]][cur_idxL[p[1]]++] = v[p[0]].size();
		} else {
			R[p[1]][cur_idxR[p[1]]++] = v[p[0]].size();
		}
	}
	w[n].clear();
	
	int last[m];
	for(int x=0;x<m;x++){
		last[x] = v[x].size();
	}
	for(int x=n-1;x>=0;x--){
		last[l[x]]--;
		for(auto p : w[x]){
			if(p[2] == 0){
				L[p[1]][cur_idxL[p[1]]++] = last[p[0]];
			} else {
				R[p[1]][cur_idxR[p[1]]++] = last[p[0]];
			}
		}
		w[x].clear();
	}
	
	int new_a[n];
	for(int x=0;x<q;x++){
		int t = que[x][0];
		
		if(pending.size() >= sz){
			fill(new_a, new_a+n, 0);
			
			for(int x=0;x<n;x++){
				int sz = v[l[x]].size();
				
				cnt[l[x]] %= sz;
				new_a[x] = a[v[l[x]][(idx[x]-cnt[l[x]]+sz)%sz].first];
			}
			for(int x=0;x<n;x++){
				a[x] = new_a[x];
				prefix[x] = a[x] + (x > 0 ? prefix[x-1] : 0);
			}
			for(int x=0;x<m;x++){
				for(int y=0;y<v[x].size();y++){
					v[x][y].second = a[v[x][y].first] + (y > 0 ? v[x][y-1].second : 0);
				}
			}
			for(auto idx : pending) cnt[idx] = 0;
			pending.clear();
		}
		
		if(t == 1){
			int l = que[x][1], r = que[x][2];
			
			l--; r--;
			
			ll lazy = 0;
			for(int y=0;y<pending.size();y++){
				int idx = pending[y];
				int idxL = L[x][y];//lower_bound(v[idx].begin(), v[idx].end(), make_pair(l, -1ll)) - v[idx].begin();
				int idxR = R[x][y];//lower_bound(v[idx].begin(), v[idx].end(), make_pair(r+1, -1ll)) - v[idx].begin();
				
				idxR--;
				if(idxL <= idxR){
					lazy -= v[idx][idxR].second - (idxL > 0 ? v[idx][idxL-1].second : 0);
					
					idxL -= cnt[idx] % v[idx].size();
					idxR -= cnt[idx] % v[idx].size();
					if(idxL < 0) idxL += v[idx].size();
					if(idxR < 0) idxR += v[idx].size();
					
					if(idxL <= idxR){
						lazy += v[idx][idxR].second - (idxL > 0 ? v[idx][idxL-1].second : 0);
					} else {
						lazy += v[idx][idxR].second + v[idx].back().second - (idxL > 0 ? v[idx][idxL-1].second : 0);
					}
				}
			}
			
			cout << prefix[r] - (l > 0 ? prefix[l-1] : 0) + lazy << "\n";
		} else {
			int p = que[x][1];
			
			p--;
			
			if(cnt[p] == 0){
				pending.push_back(p);
			}
			cnt[p]++;
		}
	}
    return 0;
}

