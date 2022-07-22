#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;
const int logN = log2(maxN)+1;

vector<int> adj[maxN];
pair<bool, int> tree[maxN];
int cnt = 0;

void dfs(int curNode, int prvNode, int k){
	tree[curNode] = {false, 0};
	
	int w = (curNode != prvNode ? 1 : 1e9);
	int dist = -1;
	int need = 0;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode, k);
			
			if(tree[nxt].first){
				dist = max(dist, tree[nxt].second);
			} else {
				need = max(need, tree[nxt].second);
			}
		}
	}
	
	if(dist >= need){
		tree[curNode] = {true, dist-w};
	} else {
		tree[curNode] = {false, need+w};
		
		if(tree[curNode].second > k){
			cnt++;
			tree[curNode] = {true, k-w};
		}
	}
	if(tree[curNode].first && tree[curNode].second < 0){
		tree[curNode] = {false, 0};
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
		
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	int left = 1, right = n;
	int ans = n;
	while(left <= right){
		int mid = (left+right) >> 1;
		
		cnt = 0;
		dfs(0, 0, mid);
		
//		cout << mid << " -> " << tree[0][2] << "\n";
		if(cnt <= k){
			ans = min(ans, mid);
			right = mid-1;
		} else {
			left = mid+1;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

