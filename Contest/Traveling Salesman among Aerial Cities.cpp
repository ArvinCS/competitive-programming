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

struct Node {
	int x, y, z;
};

short n;
Node nodes[18];

ll dist(Node a, Node b){
	return abs(b.x - a.x) + abs(b.y - a.y) + max(0, b.z - a.z);
}

ll bfs(short from, ll cost, bool visited[]){
	visited[from] = true;
	ll best = inf_ll;
	
	bool found = false;
	for(short x=2;x<=n;x++){
		if(!visited[x]){
			best = min(best, bfs(x, cost + dist(nodes[from], nodes[x]), visited));
			found = true;
		}
	}
	
	if(!found) best = dist(nodes[from], nodes[1]);
//	cout << from << " " << cost << " " << best << "\n";
	return cost + best;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;
	
	for(short x=1;x<=n;x++) cin >> nodes[x].x >> nodes[x].y >> nodes[x].z;
	
	bool visited[18];
	fill(visited, visited+18, false);
	cout << bfs(1, 0, visited) << "\n";
	
    return 0;
}

