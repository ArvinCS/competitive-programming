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
const int maxM = 3e5 + 5;

pair<int, int> tree[4*(maxN+maxM)];
int parrent[maxN+maxM], idx = 0, n, m, cnt = 0;
int inTime[maxN+maxM], outTime[maxN+maxM];
vector<int> adj[maxN+maxM];

void update(int pos, int val){
	pos += 2*(n+m);
	
	tree[pos] = {val, pos-2*(n+m)};
	for(int x=pos;x>1;x>>=1){
		tree[x>>1] = max(tree[x], tree[x^1]);
	}
}

pair<int, int> query(int left, int right){
	pair<int, int> ans = {-1, -1};
	
	for(left += 2*(n+m), right += 2*(n+m); left < right; left >>= 1, right >>= 1){
		if(left&1) ans = max(ans, tree[left++]);
		if(right&1) ans = max(ans, tree[--right]);
	}
	return ans;
}

int getParrent(int x){
	if(parrent[x] == x) return x;
	return parrent[x] = getParrent(parrent[x]);
}

void merge(int x, int y){
	int a = getParrent(x);
	int b = getParrent(y);
	
	parrent[idx] = idx;
	parrent[a] = parrent[b] = idx;
	inTime[idx] = outTime[idx] = -1;
	
	adj[idx].push_back(a);
	if(a != b) adj[idx].push_back(b);
	idx++;
}

void dfs(int curNode, int prvNode){
	inTime[curNode] = cnt++;
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode);
		}
	}
	
	outTime[curNode] = cnt++;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int q;
	cin >> n >> m >> q;
	
	int val[n];
	for(int x=0;x<n;x++){
		cin >> val[x];
	}
	
	vector<pair<int, int>> edges;
	bool safe[m];
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		edges.push_back({a, b});
		safe[x] = true;
	}
	
	vector<pair<int, int>> v;
	for(int x=0;x<q;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		v.push_back({a, b});
		
		if(a == 1){
			safe[b] = false;
		}
	}
	
	for(int x=0;x<n+m;x++){
		inTime[x] = outTime[x] = -1;
		parrent[x] = x;
	}
	
	idx = n;
	for(int x=0;x<m;x++){
		if(safe[x]){
			merge(edges[x].first, edges[x].second);
		}
	}
	
	fill(tree, tree+2*(n+m), make_pair(0,0));
	
	int node[q];
	for(int x=q-1;x>=0;x--){
		pair<int, int> p = v[x];
		
		if(p.first == 0){
			node[x] = getParrent(p.second);
		} else {
			merge(edges[p.second].first, edges[p.second].second);
		}
	}
	
	for(int x=idx-1;x>=0;x--){
		if(inTime[x] == -1 && outTime[x] == -1){
			dfs(x, x);
		}
	}
	
//	cout << "--\n";
//	for(int x=0;x<idx;x++){
//		cout << inTime[x] << " " << outTime[x] << "\n";
//	}
	
	for(int x=0;x<n;x++){
		update(inTime[x], val[x]);
	}
	
	for(int x=0;x<q;x++){
		pair<int, int> p = v[x];
		
		if(p.first == 0){
			pair<int, int> ans = query(inTime[node[x]], outTime[node[x]]);
			
//			cout << node[x] << "-\n";
			cout << ans.first << "\n";
			
			update(ans.second, 0);
		}
	}
    return 0;
}

