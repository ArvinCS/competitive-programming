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

vector<int> adj[maxN];
int length[maxN];

int dfs(int curNode, int prvNode){
	if(curNode != prvNode && adj[curNode].size() == 1){
		length[curNode] = 0;
		return 1;
	}
	
	int ans = 0;
	
	priority_queue<pair<int, int>> pq;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			ans = max(ans, dfs(nxt, curNode));
			length[curNode] = min(length[curNode], length[nxt]+1);
			pq.push({length[nxt], nxt});
		}
	}
	
	if(curNode == prvNode){
		int mn = inf_int;
		for(auto nxt : adj[curNode]){
			if(nxt != prvNode){
				while(!pq.empty() && pq.top().second == nxt) pq.pop();
				
				mn = min(mn, max(length[nxt]+1, (!pq.empty() ? pq.top().first+2 : 0)));
				pq.push({length[nxt], nxt});
			}
		}
		
		ans = max(ans, mn);
	} else {
		while(pq.size() > 1){
			ans = max(ans, pq.top().first+2);
			pq.pop();
		}
	}
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		for(int x=0;x<n;x++){
			adj[x].clear();
			length[x] = inf_int;
		}
		for(int x=0;x<n-1;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		cout << dfs(0, 0) << "\n";
		
//		for(int x=0;x<n;x++){
//			cout << length[x] << " ";
//		}
//		cout << "\n";
	}

    return 0;
}

