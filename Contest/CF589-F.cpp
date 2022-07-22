#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 18;
const int maxM = (1 << maxN);

vector<int> adj[maxM];
int parent[maxM], dep[maxM], cnt[maxM], mx[maxM];

int dfs(int curNode, int prvNode, int depth){
	parent[curNode] = prvNode;
	dep[curNode] = depth;
	mx[curNode] = depth;
	cnt[curNode] = 0;
	
	if(adj[curNode].size() >= 4){
		cnt[curNode]++;
	}
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			mx[curNode] = max(mx[curNode], dfs(nxt, curNode, depth+1));
			sz[curNode] += sz[nxt];
			cnt[curNode] += cnt[nxt];
		}
	}
	
	return mx[curNode];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int m = (1 << n)-1;
	for(int x=0;x<m-2;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dfs(0, 0, 1);
	
	vector<int> v;
	for(int x=0;x<m-1;x++){
		// if x became the parent of m-1
		
		if(adj[x].size() <= 4){
			bool valid = false;
			for(int i=0;i<adj[x].size();i++){ // i act as a parent
				for(int l=0;l<adj[x].size();l++){ // l act as a neighbour of the m-1
					if(i == l) continue;
					if(adj[x][l] == parent[x]){
						if(m-2-cnt[x] != 0) continue;
					} else {
						if(cnt[l] != 0) continue;
					}
					
					int dl = 0, di = 0;
					if(adj[x][l] == parent[x]){
						dl = n-mx[x];
					} else {
						if(cnt[l] != 0) continue;
					}
				}
			}
			
			if(valid) v.push_back(x);
		} else {
			// proof if there exists x such that deg[x] > 4 then tree is invalid for all possibilities
			// deg for all x in normal perfect binary tree is 1 <= deg[x] <= 3
			// then if we want to do the operation on some x, it contributes max -1 + 2 = +1 to the deg[x] and min -1
			// so max deg[x] is 4.
			
			v.clear();
			break;
		}
	}
	
	cout << v.size() << "\n";
	for(int x=0;x<v.size();x++){
		if(x > 0) cout << " ";
		cout << v[x]+1;
	}
	cout << "\n";
    return 0;
}

