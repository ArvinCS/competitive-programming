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

const int maxN = 1e5 + 5;

ll dist[maxN];

struct Node {
	ll dist, pending;
	int from, curNode;
	bool bridge;
	
 	Node(ll dist, ll pending, int curNode, bool bridge) : dist(dist), pending(pending), curNode(curNode), bridge(bridge) {
		
	}
	
	bool operator >(const Node& b) const {
		if(dist == b.dist){
			if(pending == b.pending){
				return bridge > b.bridge;
			}
			return pending > b.pending;
		}
		return dist > b.dist;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	vector<pair<int, int>> adj[n];
	for(int x=0;x<m;x++){
		int a, b, c;
		cin >> a >> b >> c;
		
		a--; b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	
	ll dist[n], pending[n];
	fill(dist, dist+n, inf_ll);
	fill(pending, pending+n, inf_ll);
	
	dist[0] = 0;
	
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	pq.push(Node(dist[0], 0, 0, false));
	
	while(!pq.empty()){
		Node node = pq.top();
		pq.pop();
		
		if(node.bridge){
			if(pending[node.curNode] < node.pending) continue;
			for(auto nxt : adj[node.curNode]){
				ll tmp = (nxt.second+node.pending);
				if(dist[nxt.first] > node.dist+tmp*tmp){
					dist[nxt.first] = node.dist+tmp*tmp;
					pq.push(Node(dist[nxt.first], 0, nxt.first, false));
				}
			}
		} else {
			if(dist[node.curNode] < node.dist) continue;
			for(auto nxt : adj[node.curNode]){
				if(pending[nxt.first] > nxt.second){
					pending[nxt.first] = nxt.second;
					pq.push(Node(node.dist, nxt.second, nxt.first, true));
				}
			}
		}
//		cout << node.dist << " " << node.pending << " " << node.curNode << " " << node.bridge << "\n";
	}
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << (dist[x] == inf_ll ? -1 : dist[x]);
	}
	cout << "\n";
    return 0;
}
 
