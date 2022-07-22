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

const int maxN = 1e3 + 5;

vector<int> adj[maxN];
vector<pair<int, int>> edge;
int level[maxN], parrent[maxN];
set<int> prefix[maxN];

void dfs(int curNode, int prvNode){
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			edge.push_back({curNode, nxt});
			
			level[nxt] = level[curNode]+1;
			parrent[nxt] = curNode;
			dfs(nxt, curNode);
		}
	}
}

int ask(set<int> w){
	cout << "? " << w.size();
	for(auto node : w){
		cout << " " << node+1;
	}
	cout << endl;
	
	int ans;
	cin >> ans;
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n;
	cin >> n;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	parrent[0] = 0;
	level[0] = 0;
	dfs(0, 0);
	
	for(int x=0;x<edge.size();x++){
		prefix[x].insert(edge[x].first);
		prefix[x].insert(edge[x].second);
		
		if(x > 0){
			for(auto node : prefix[x-1]){
				prefix[x].insert(node);
			}
		}
	}
	
	ll mx = ask(prefix[edge.size()-1]);
	
	int left = 0, right = edge.size()-1;
	int bound = right;
	while(left <= right){
		int mid = (left+right) >> 1;
		
		if(ask(prefix[mid]) == mx){
			bound = min(bound, mid);
			right = mid-1;
		} else {
			left = mid+1;
		}
	}
	
	cout << "! " << edge[bound].first+1 << " " << edge[bound].second+1 << endl;
    return 0;
}

