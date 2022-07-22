# include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

vector<pair<int, int>> adj[maxN];
int sz[maxN];
ll dist[maxN], cost[maxN];

void dfs(int curNode, int prvNode){
    sz[curNode] = 1;
    for(auto nxt : adj[curNode]){
        if(nxt.first != prvNode){
            dist[nxt.first] = dist[curNode]+nxt.second;
            dfs(nxt.first, curNode);
            sz[curNode] += sz[nxt.first];
        }
    } 
}

void dfs2(int curNode, int prvNode){
	for(auto nxt : adj[curNode]){
		if(nxt.first != prvNode){
			cost[nxt.first] = cost[curNode] + 2*(dist[curNode]*(sz[curNode]-sz[nxt.first]));
			dfs2(nxt.first, curNode);
		}
	}
}

int main(){
    int n;
    cin >> n;
    
    for(int x=0;x<n-1;x++){
        int a, b, c;
        cin >> a >> b >> c;
        
        a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    dist[0] = cost[0] = 0;
    
    dfs(0, 0);
    dfs2(0, 0);
    
    ll sum = 0;
    for(int x=0;x<n;x++){
        sum += dist[x];
    }
    
    int k;
    cin >> k;
    
    for(int i=0;i<k;i++){
        int root;
        cin >> root;
        
        root--;
        
        int remain = n-sz[root];
        
        ll ans = sum - sz[root]*dist[root] - cost[root] + (remain*dist[root]);
        
        if(i > 0) cout << " ";
        cout << ans;
    }
    cout << "\n";
  return 0;
}

