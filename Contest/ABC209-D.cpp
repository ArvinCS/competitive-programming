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
const int lgN = log2(maxN)+1;

int parrent[lgN+1][maxN];
vector<int> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	int dist[n];
	fill(dist, dist+n, 0);
	
	queue<pair<int, int>> q;
	dist[0] = 0;
	parrent[0][0] = 0;
	q.push({0, 0});
	
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		
//		cout << p.first << " " << dist[p.first] << " " << p.second << "\n";
		for(int x=1;x<=lgN;x++){
			parrent[x][p.first] = parrent[x-1][parrent[x-1][p.first]];
		}
		for(auto nxt : adj[p.first]){
			if(nxt != p.second){
				dist[nxt] = dist[p.first]+1;
				parrent[0][nxt] = p.first;
				q.push({nxt, p.first});
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		int c, d;
		cin >> c >> d;
		
		c--; d--;
		
		int total = dist[c] + dist[d];
		
		if(dist[c] < dist[d]) swap(c, d);
		for(int x=lgN;x>=0;x--){
			if(dist[c]-(1 << x) >= dist[d]){
				c = parrent[x][c];
			}
		}
		for(int x=lgN;x>=0;x--){
			if(c == d) break;
			if(parrent[x][c] == parrent[x][d]){
				c = parrent[x][c];
				break;
			}
		}
		
		total -= 2*dist[parrent[0][c]];
//		cout << total << "\n";
		if(total%2 == 0){
			cout << "Town\n";
		} else {
			cout << "Road\n";
		}
	}
    return 0;
}

