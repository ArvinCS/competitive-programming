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
int childLeaf[maxN];
bool bud[maxN], leaf[maxN], last[maxN];

void dfs(int curNode, int prvNode){
	int cnt = 0, cnt2 = 0;
	
	if(curNode != prvNode && adj[curNode].size() == 1){
		leaf[curNode] = true;
	}
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode);
			if(leaf[nxt]) cnt++;
			if(bud[nxt]) cnt2++;
		}
	}
	
	childLeaf[curNode] = cnt;
//	cout << curNode << " " << leaf[curNode] << " -> " << cnt << " " << cnt2 << "\n";
	if(cnt == adj[curNode].size()-1-cnt2){
		if(cnt > 0 && !leaf[curNode]){
			bud[curNode] = true;
		} else {
			leaf[curNode] = true;
		}
	}
}

void dfs2(int curNode, int prvNode){
	if(bud[curNode]) return;
	
	int cnt = 0;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			if(bud[nxt]) cnt++;
		}
	}
	
	if(cnt == adj[curNode].size()-1){
		last[curNode] = true;
	} else {
		for(auto nxt : adj[curNode]){
			if(nxt != prvNode){
				dfs2(nxt, curNode);
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

	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		for(int x=0;x<n;x++){
			adj[x].clear();
			childLeaf[x] = 0;
			bud[x] = leaf[x] = last[x] = false;
		}
		for(int x=0;x<n-1;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		dfs(0, 0);
		dfs2(0, 0);
		
		priority_queue<pair<int, int>> pq;
		for(int x=0;x<n;x++){
			if(last[x]){
				pq.push({1, x});
			}
		}
		
		for(int x=0;x<n;x++){
			if(bud[x]){
				if(!pq.empty()){
					pair<int, int> p = pq.top();
					pq.pop();
					
					p.first--;
					
					if(p.first > 0){
						pq.push(p);
					}
				}
				pq.push({childLeaf[x], x});
			}
		}
		
		int ans = 0;
		while(!pq.empty()){
			ans += pq.top().first;
			pq.pop();
		}
		
		cout << ans << "\n";
	}

    return 0;
}

