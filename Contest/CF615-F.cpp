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

const int maxN = 2e5 + 5;

vector<pair<int, int>> adj[maxN];
int n, w[maxN];
pair<int, int> parrent[maxN];

void bfs(int source, int dist[]){
	fill(dist, dist+n, inf_int);
	
	queue<pair<int, int>> q;
	parrent[source] = {source, -1};
	dist[source] = 0;
	q.push({dist[source], source});
	
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		
		for(auto nxt : adj[p.second]){
			if(dist[nxt.first] > p.first+w[nxt.second]){
				dist[nxt.first] = p.first+w[nxt.second];
				parrent[nxt.first] = {p.second, nxt.second};
				q.push({dist[nxt.first], nxt.first});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		w[x] = 1;
		adj[a].push_back({b, x});
		adj[b].push_back({a, x});
	}
	
	int distA[n], distB[n], distC[n];
	
	bfs(0, distA);
	
	int a = 0, b = 0, c = 0;
	for(int x=1;x<n;x++){
		if(distA[x] > distA[a]){
			a = x;
		}
	}
	
	bfs(a, distA);
	
	for(int x=1;x<n;x++){
		if(distA[x] > distA[b]){
			b = x;
		}
	}
	
	int node = b;
	while(node != a){
		w[parrent[node].second] = 0;
		node = parrent[node].first;
	}
	
	bfs(b, distB);
	
	for(int x=0;x<3;x++){
		if(x != a && x != b){
			c = x;
			break;
		}
	}
	
	for(int x=0;x<n;x++){
		if(x != a && x != b && distB[x] > distB[c]){
			c = x;
		}
	}
	
	cout << distA[b]+distB[c] << "\n";
	cout << a+1 << " " << b+1 << " " << c+1 << "\n";
    return 0;
}

