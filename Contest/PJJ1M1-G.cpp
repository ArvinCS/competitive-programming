#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;
const int logN = log2(maxN);

vector<int> adj[maxN];
int level[maxN], sz[maxN];
int parrent[maxN][logN+1];

void dfs(int curNode, int prvNode){
	for(int x=1;x<=logN;x++){
		parrent[curNode][x] = parrent[parrent[curNode][x-1]][x-1];
	}
	
	sz[curNode] = 1;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			parrent[nxt][0] = curNode;
			level[nxt] = level[curNode]+1;
			dfs(nxt, curNode);
			sz[curNode] += sz[nxt];
		}
	}
}

int lca(int x, int y){
	if(level[x] > level[y]) swap(x, y);
	
	for(int i=logN;i>=0;i--){
		if(level[x] <= level[y]-(1 << i)){
			y = parrent[y][i];
		}
	}
	
	if(x == y) return x;
	
	for(int i=logN;i>=0;i--){
		if(parrent[x][i] != parrent[y][i]){
			x = parrent[x][i];
			y = parrent[y][i];
		}
	}
	return parrent[x][0];
}

int jump(int x, int y){
	int ans = x;
	for(int i=logN;i>=0;i--){
		if(y >= (1 << i)){
			y -= (1 << i);
			ans = parrent[ans][i];
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	parrent[0][0] = 0;
	dfs(0, 0);
	
	int m;
	cin >> m;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		if(a == b){
			cout << n << "\n";
			continue;
		}
		
		if(level[a] > level[b]) swap(a, b);
		int dist = level[b]+level[a]-2*level[lca(a, b)];
		if(dist % 2 == 1){
			cout << "0\n";
			continue;
		}
		
		int c = jump(b, dist/2);
		if(lca(a, c) == c){
			cout << n-sz[jump(b, dist/2-1)]-sz[jump(a, dist/2-1)] << "\n";
		} else {
			cout << sz[c]-sz[jump(b, dist/2-1)] << "\n";
		}
	}
    return 0;
}

