#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 3e5 + 5;

struct DSU {
	int parent[maxN], sz[maxN];
	
	void reset(int n){
		for(int x=0;x<=n;x++){
			parent[x] = x;
			sz[x] = 1;
		}
	}	
	
	int getParent(int x){
		if(parent[x] == x) return x;
		return parent[x] = getParent(parent[x]);
	}
	
	bool merge(int x, int y){
		int a = getParent(x);
		int b = getParent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			parent[b] = a;
			sz[a] += sz[b];
			return true;
		}
		return false;
	}
} dsu;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	pair<int, int> p[m];
	vector<int> v[2];
	for(int x=0;x<m;x++){
		int a, b, c;
		cin >> a >> b >> c;
		
		a--; b--;
		
		if(a == b) continue;
		
		v[c%2].push_back(x);
		p[x] = {a, b};
	}
	
	sort(v[1].begin(), v[1].end());
	v[1].erase(unique(v[1].begin(), v[1].end()), v[1].end());
	
	dsu.reset(n);
	
	vector<int> ans;
	int cnt = n;
	for(int x=0;x<v[0].size();x++){
		int idx = v[0][x];
		if(dsu.merge(p[idx].first, p[idx].second)){
			cnt--;
			ans.push_back(idx);
		}
	}
	
	if(cnt == 1){
		sort(ans.begin(), ans.end());
		assert(ans.size() == n-1);
		cout << "YES\n";
		for(int x=0;x<ans.size();x++){
			if(x > 0) cout << " ";
			cout << ans[x]+1;
		}
		cout << "\n";
		return 0;
	} else if(cnt > 1){
		int idx2 = -1;
		for(int x=0;x<v[1].size();x++){
			int idx = v[1][x];
			if(dsu.getParent(p[idx].first) == dsu.getParent(p[idx].second)){
				assert(p[idx].first != p[idx].second);
				idx2 = idx;
				break;
			}
		}
		
		int cnt2 = 0;
		for(int x=0;x<v[1].size();x++){
			int idx = v[1][x];
			if(dsu.merge(p[idx].first, p[idx].second)){
				cnt--;
				cnt2++;
				ans.push_back(idx);
			}
		}
		
		if(cnt == 1){
			if(cnt2%2 == 0){
				sort(ans.begin(), ans.end());
				assert(ans.size() == n-1);
				cout << "YES\n";
				for(int x=0;x<ans.size();x++){
					if(x > 0) cout << " ";
					cout << ans[x]+1;
				}
				cout << "\n";
				return 0;
			} else if(idx2 != -1){
				dsu.reset(n);
				ans.clear();
				
				ans.push_back(idx2);
				dsu.merge(p[idx2].first, p[idx2].second);
				cnt = n-1;
				for(int x=0;x<v[0].size();x++){
					int idx = v[0][x];
					if(dsu.merge(p[idx].first, p[idx].second)){
						cnt--;
						ans.push_back(idx);
					}
				}
				
				cnt2 = 1;
				for(int x=0;x<v[1].size();x++){
					int idx = v[1][x];
					if(dsu.merge(p[idx].first, p[idx].second)){
						cnt--;
						cnt2++;
						ans.push_back(idx);
					}
				}
				
				if(cnt == 1 && cnt2%2 == 0){
					sort(ans.begin(), ans.end());
					assert(ans.size() == n-1);
					cout << "YES\n";
					for(int x=0;x<ans.size();x++){
						if(x > 0) cout << " ";
						cout << ans[x]+1;
					}
					cout << "\n";
					return 0;
				}
				assert(cnt2%2 == 0);
			} else if(idx2 == -1){
				dsu.reset(n);
				ans.clear();
				
				cnt = n;
				cnt2 = 0;
				for(int x=0;x<v[1].size();x++){
					int idx = v[1][x];
					if(dsu.merge(p[idx].first, p[idx].second)){
						cnt--;
						cnt2++;
						ans.push_back(idx);
					}
				}
				
				for(int x=0;x<v[0].size();x++){
					int idx = v[0][x];
					if(dsu.merge(p[idx].first, p[idx].second)){
						cnt--;
						ans.push_back(idx);
					}
				}
				
				if(cnt == 1 && cnt2%2 == 0){
					sort(ans.begin(), ans.end());
					assert(ans.size() == n-1);
					cout << "YES\n";
					for(int x=0;x<ans.size();x++){
						if(x > 0) cout << " ";
						cout << ans[x]+1;
					}
					cout << "\n";
					return 0;
				}
			}
		}
	}
	
	cout << "NO" << "\n";
    return 0;
}

