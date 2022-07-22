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

const int maxN = 3e5 + 5;

vector<int> adj[maxN];
int parrent[maxN], sz[maxN];
bool visited[maxN], picked[maxN];
vector<int> ans;

int getParrent(int x){
	if(parrent[x] == x) return x;
	return parrent[x] = getParrent(parrent[x]);
}

void merge(int x, int y){
	int a = getParrent(x);
	int b = getParrent(y);
	
	if(a != b){
		if(sz[a] < sz[b]){
			swap(a, b);
		}
		
		parrent[b] = a;
		sz[a] += sz[b];
	}
}

bool check(int x, int y){
	return getParrent(x) != getParrent(y);
}

void dfs(int curNode){
	visited[curNode] = true;
	
	if(!picked[curNode]){
		ans.push_back(curNode);
		
		for(auto nxt : adj[curNode]){
			picked[nxt] = true;
		}
	}
	
	for(auto nxt : adj[curNode]){
		if(!visited[nxt]){
			dfs(nxt);
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
		int n, m;
		cin >> n >> m;
		
		ans.clear();
		for(int x=0;x<n;x++){
			adj[x].clear();
			parrent[x] = x;
			sz[x] = 1;
			visited[x] = picked[x] = false;
		}
		
		int cnt = n;
		for(int x=0;x<m;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
			
			if(check(a, b)){
				merge(a, b);
				cnt--;
			}
		}
		
		if(cnt > 1){
			cout << "NO\n";
			continue;
		}
		
		dfs(0);
		
		cout << "YES\n";
		cout << ans.size() << "\n";
		for(int x=0;x<ans.size();x++){
			if(x > 0) cout << " ";
			cout << ans[x]+1;
		}
		cout << "\n";
	}

    return 0;
}

