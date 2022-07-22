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

int n;
int data[maxN], table[maxN];
vector<int> adj[maxN];

void bfs(bool odd){	
	int dist[n];
	fill(dist, dist+n, inf_int);
	
	queue<int> q;
	for(int x=0;x<n;x++){
		if(data[x] % 2 == odd){
			q.push(x);
			dist[x] = 0;
		}
	}
	
	while(!q.empty()){
		int curNode = q.front();
		q.pop();
				
		for(auto nxt : adj[curNode]){
			if(dist[nxt] == inf_int){
				dist[nxt] = dist[curNode] + 1;
				q.push(nxt);
			}
		}
	}
	
	for(int x=0;x<n;x++){
		if(data[x] % 2 == !odd && dist[x] != inf_int) table[x] = dist[x];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> data[x];
		int left = x-data[x], right = x+data[x];
		if(left >= 0) adj[left].push_back(x);
		if(right < n) adj[right].push_back(x);
	}
	
	fill(table, table+n, inf_int);
	
	bfs(0);
	bfs(1);
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << (table[x] == inf_int ? -1 : table[x]);
	}
	cout << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

