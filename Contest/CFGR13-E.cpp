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

bool fib[maxN];
pair<int, int> track[maxN];
int sz[maxN];
vector<pair<int, int>> adj[maxN];
bool possible = true;

int getSize(int curNode, int prvNode){
	sz[curNode] = 1;
	for(auto &nxt : adj[curNode]){
		if(nxt.first != prvNode && nxt.second){
			sz[curNode] += getSize(nxt.first, curNode);
		}
	}
	
	return sz[curNode];
}

pair<int, int> cut(int curNode, int prvNode, int val){
	for(auto &nxt : adj[curNode]){
		if(nxt.first != prvNode && nxt.second){
			if(sz[nxt.first] == track[val].first || sz[nxt.first] == track[val].second){
				return {curNode, nxt.first};
			}
			
			pair<int, int> tmp = cut(nxt.first, curNode, val);
			if(tmp.first != -1) return tmp;
		}
	}
	return {-1, -1};
}

void solve(int curNode, int val){
	if(val <= 1) return;
	
	getSize(curNode, curNode);
	pair<int, int> edge = cut(curNode, curNode, val);
	
	if(edge.first == -1 || !possible){
		possible = false;
		return;
	}
	
	for(auto &nxt : adj[edge.first]){
		if(nxt.first == edge.second) nxt.second = false; // block edge
	}
	for(auto &nxt : adj[edge.second]){
		if(nxt.first == edge.first) nxt.second = false; // block edge
	}
	
	solve(edge.first, (sz[edge.second] == track[val].first ? track[val].second : track[val].first));
	solve(edge.second, (sz[edge.second] == track[val].first ? track[val].first : track[val].second));
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	fill(fib, fib+maxN, false);
	
	int a = 1, b = 1;
	fib[a] = true;
	while(a+b < maxN){
		int c = a+b;
		
		fib[c] = true;
		track[c] = {a, b};
		
		b = a;
		a = c;
	}
	
	int n;
	cin >> n;
	
	for(int x=0;x<n-1;x++){
		int c, d;
		cin >> c >> d;
		
		c--; d--;
		adj[c].push_back({d, true});
		adj[d].push_back({c, true});
	}
	
	if(!fib[n]){
		cout << "NO\n";
		return 0;
	}
	
	solve(0, n); // get all size of subtree and make sure it possible to form a fib-tree
	
	if(possible){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
    return 0;
}

