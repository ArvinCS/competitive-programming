#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

vector<int> adj[maxN];
int lt[maxN], rt[maxN], t = 1;

void dfs(int curNode, int prvNode){
	lt[curNode] = 1e9;
	rt[curNode] = 0;
	
	bool leaf = true;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			leaf = false;
			dfs(nxt, curNode);
			
			lt[curNode] = min(lt[curNode], lt[nxt]);
			rt[curNode] = max(rt[curNode], rt[nxt]);
		}
	}
	
	if(leaf){
		lt[curNode] = rt[curNode] = t++;
	}
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
	
	dfs(0, -1);
	
	for(int x=0;x<n;x++){
		cout << lt[x] << " " << rt[x] << "\n";
	}
    return 0;
}

