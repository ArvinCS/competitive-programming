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

vector<int> adj[30];

int bfs(int sourceNode, int targetNode){
	int dist[26];
	fill(dist, dist+26, inf_int);
	
	queue<int> q;
	dist[sourceNode] = 0;
	q.push(sourceNode);
	
	while(!q.empty()){
		int curNode = q.front();
		q.pop();
		
		for(auto nxt : adj[curNode]){
			if(dist[nxt] > dist[curNode]+1){
				dist[nxt] = dist[curNode]+1;
				q.push(nxt);
			}
		}
	}
	
	return dist[targetNode];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("consistency_chapter_2_validation_input.txt","r",stdin);
//	freopen("consistency_chapter_2_validation_output.txt","w",stdout);

	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		string s;
		cin >> s;
		
		int k;
		cin >> k;
		
		for(int x=0;x<26;x++) adj[x].clear();
		for(int x=0;x<k;x++){
			char a, b;
			cin >> a >> b;
			
			adj[(a - 'A')].push_back((b - 'A'));
		}
		
		ll ans = inf_int;
		for(int x=0;x<26;x++){
			ll val = 0;
			for(int y=0;y<s.length();y++){
				val += bfs((s[y] - 'A'), x);
			}
			
			ans = min(ans, val);
		}
		
		cout << "Case #" << i << ": " << (ans != inf_int ? ans : -1) << "\n";
	}

    return 0;
}

