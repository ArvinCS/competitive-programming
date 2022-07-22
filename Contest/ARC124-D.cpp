#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

struct DSU {
	int parrent[2*maxN], cnt[2*maxN][2];
	
	int getParrent(int x){
		if(parrent[x] == x) return x;
		return parrent[x] = getParrent(parrent[x]);
	}
	
	pair<int, int> getCnt(int x){
		return {cnt[x][0], cnt[x][1]};
	}
	
	void merge(int x, int y){
		int a = getParrent(x);
		int b = getParrent(y);
		
		if(a != b){
			parrent[b] = a;
			
			cnt[a][0] += cnt[b][0];
			cnt[a][1] += cnt[b][1];
		}
	}
};

DSU dsu;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int p[n+m];
	for(int x=0;x<n+m;x++){
		cin >> p[x];
		p[x]--;
	}
	
	for(int x=0;x<n+m;x++){
		dsu.parrent[x] = x;
		dsu.cnt[x][(x < n ? 0 : 1)] = 1;
		dsu.cnt[x][(x < n ? 0 : 1)^1] = 0;
	}
	
	for(int x=0;x<n+m;x++){
		dsu.merge(x, p[x]);
	}
	
	bool visited[n+m];
	fill(visited, visited+n+m, false);
	
	int ans = 0, left = 0, right = 0;
	for(int x=0;x<n+m;x++){
		int par = dsu.getParrent(x);
		if(!visited[par]){
			visited[par] = true;
			
			int sz = dsu.cnt[par][0] + dsu.cnt[par][1];
			
			if(sz > 1){
				ans += sz-1;
				if(dsu.cnt[par][0] == 0){
					left++;
				}
				if(dsu.cnt[par][1] == 0){
					right++;
				}
			}
		}
	}
	ans += max(left, right)*2;
	
	cout << ans << "\n";
    return 0;
}

