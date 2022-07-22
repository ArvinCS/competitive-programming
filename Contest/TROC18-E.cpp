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
int tree[2*maxN][2], inTime[maxN], outTime[maxN], t = 0;
int part[maxN];

void update(int pos, int val, int id){
	pos++;
	
	while(pos < 2*maxN){
		tree[pos][id] ^= val;
		pos += pos&(-pos);
	}
}

int query(int pos, int id){
	pos++;
	
	int ans = 0;
	while(pos > 0){
		ans ^= tree[pos][id];
		pos -= pos&(-pos);
	}
	return ans;
}

void dfs(int curNode, int prvNode, int id){
	part[curNode] = id;
	inTime[curNode] = t++;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode, id^1);
		}
	}
	outTime[curNode] = t++;
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
	
	dfs(0, 0, 0);
	
	fill(tree[0], tree[2*n+1], 0);
	
	int q;
	cin >> q;
	
	for(int i=1;i<=q;i++){
		int t;
		cin >> t;
		
		if(t == 1){
			int node, val;
			cin >> node >> val;
			
			node--;
			
			update(inTime[node], val, part[node]);
			update(outTime[node], val, part[node]);
		} else {
			int node;
			cin >> node;
			
			node--;
			
			cout << query(inTime[node], part[node]) << "\n";
		}
	}
    return 0;
}

