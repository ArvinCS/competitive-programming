#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

vector<int> adj[maxN];
int b[maxN], p[maxN], pos = 0;
int inTime[maxN], outTime[maxN], cur = 0;

void dfs(int curNode, int prvNode){
	inTime[curNode] = cur++;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode);
		}
	}
	outTime[curNode] = cur++;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		pos = 0;
		cur = 0;
		for(int x=0;x<n;x++){
			adj[x].clear();
		}
		for(int x=0;x<n;x++){
			cin >> b[x];
			b[x]--;
			
			if(b[x] != x){
				adj[b[x]].push_back(x);
				adj[x].push_back(b[x]);
			}
		}
		for(int x=0;x<n;x++){
			cin >> p[x];
			p[x]--;
		}
		
		int root = 0;
		for(int x=0;x<n;x++){
			if(b[x] == x){
				root = x;
				break;
			}
		}
		
		dfs(root, root);
		
		bool done[n];
		fill(done, done+n, false);
		
		int ans[n], sum[n];
		ans[p[0]] = 0;
		sum[p[0]] = 0;
		done[p[0]] = true;
		
		bool valid = true;
		for(int x=1;x<n;x++){
			if(!done[b[p[x]]]){
				valid = false;
				break;
			}
			if(p[x-1] != b[p[x]]){
				ans[p[x]] = sum[p[x-1]]+1-sum[b[p[x]]];
			} else {
				ans[p[x]] = 1;
			}
			
			sum[p[x]] = ans[p[x]] + sum[b[p[x]]];
			done[p[x]] = true;
		}
		
		if(valid){
			for(int x=0;x<n;x++){
				if(x > 0) cout << " ";
				cout << ans[x];
			}
			cout << "\n";
		} else {
			cout << "-1\n";
		}
	}
	return 0;
}

