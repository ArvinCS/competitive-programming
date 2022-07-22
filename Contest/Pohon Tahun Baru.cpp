#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

const int maxN = 2 * 1e5 + 5;

vector<int> adj[maxN];
int parrent[maxN];
int arr[maxN];

int getParrent(int curNode){
	if(parrent[curNode] == curNode) return curNode;
	return getParrent(parrent[curNode]);
}

int getXOR(int curNode){
	if(parrent[curNode] == curNode) return arr[curNode];
	return arr[curNode] ^ getXOR(parrent[curNode]);
}

int getAnswer(int curNode){
	if(parrent[curNode] == curNode) return getXOR(curNode);
	return getXOR(curNode) ^ getAnswer(parrent[curNode]);
}

void dfs(int curNode, bool visited[]){
	visited[curNode] = true;
	
	for(auto v : adj[curNode]){
		parrent[v] = curNode;
		if(!visited[v]){
			visited[v] = true;
			dfs(v, visited);
		}
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
	
	bool visited[n];
	fill(visited, visited+n, false);
	fill(arr, arr+n, 0);
	
	dfs(0, visited);
	
	int q;
	cin >> q;
	
	while(q--){
		int t;
		cin >> t;
		
		if(t == 1){
			int u, x;
			cin >> u >> x;
			
			arr[u] = (arr[u] == -1 ? x : arr[u] ^ x);
		} else {
			int u;
			cin >> u;
			
			cout << parrent[u-1] << "\n";
//			cout << getAnswer(u-1) << "\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

