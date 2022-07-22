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

const int maxN = 3e5 + 40;

pair<int, int> tree[4*maxN];
int inTime[maxN], outTime[maxN], n, t = 0;
vector<int> adj[maxN][2];

pair<int, int> query(int left, int right){ // [l, r)
	pair<int, int> ans = {-1, -1};
	
	for(left += 2*n, right += 2*n; left < right; left>>=1, right>>=1){
		if(left&1){
			ans = max(ans, tree[left++]);
		}
		if(right&1){
			ans = max(ans, tree[--right]);
		}
	}
	
	return ans;
}

void update(int pos, pair<int, int> val){
	pos += 2*n;
	
	tree[pos] = val;
	for(int x=pos;x>1;x>>=1){
		tree[x>>1] = max(tree[x], tree[x^1]);
	}
}

void dfs(int curNode){
	inTime[curNode] = t++;
	
	for(auto nxt : adj[curNode][1]){
		dfs(nxt);
	}
	
	outTime[curNode] = t++;
}

int dfs2(int curNode, int cnt){
	pair<int, int> ancestor = query(0, inTime[curNode]);
//	cout << curNode << " " << ancestor.second << " " << ancestor.first << "\n";
	if(ancestor.first > outTime[curNode]){
		update(ancestor.second, {-1, -1});
		cnt--;
	}
	
	pair<int, int> child = query(0, outTime[curNode]);
	
	bool hasChild = (child.second > inTime[curNode] && child.first < outTime[curNode]);
	if(!hasChild){
		update(inTime[curNode], {outTime[curNode], inTime[curNode]});
		cnt++;
	}
	
	int ans = 0;
	if(adj[curNode][0].size() == 0){
//		cout << curNode << " " << cnt << " " << hasChild << "\n";
		ans = max(ans, cnt);
	} else {
		for(auto nxt : adj[curNode][0]){
			ans = max(ans, dfs2(nxt, cnt));
		}
	}
	
	if(ancestor.first > outTime[curNode]){
		update(ancestor.second, ancestor);
		cnt--;
	}
	if(!hasChild){
		update(inTime[curNode], {-1, -1});
		cnt--;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int tc;
	cin >> tc;
	
	while(tc--){
		t = 0;
		cin >> n;
		
		fill(tree, tree+4*(n+10), make_pair(-1, -1));
		for(int x=0;x<n;x++){
			adj[x][0].clear();
			adj[x][1].clear();
		}
		for(int x=1;x<n;x++){
			int p;
			cin >> p;
			
			adj[p-1][0].push_back(x);
		}
		for(int x=1;x<n;x++){
			int p;
			cin >> p;
			
			adj[p-1][1].push_back(x);
		}
		
		dfs(0);
		
		int ans = dfs2(0, 0);
		cout << ans << "\n";
	}
    return 0;
}

