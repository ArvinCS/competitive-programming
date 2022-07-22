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

const int maxN = 5e5 + 5;

vector<int> adj[2*maxN];
bool visited[2*maxN];
int cnt2 = 0;

bool dfs(int curNode, int prvNode){
	visited[curNode] = true;
	cnt2++;
		
	bool ans = true;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			if(visited[nxt]){
				ans = false;
			} else {
				ans &= dfs(nxt, curNode);
			}
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
	
	int n;
	cin >> n;
	
	vector<pair<int, int>> v, w;
	int l[n], r[n];
	for(int x=0;x<n;x++){
		cin >> l[x] >> r[x];
		
		v.push_back({l[x], x});
		v.push_back({r[x], x});
	}
	
	sort(v.begin(), v.end());
	
	int cnt = 0;
	set<int> st;
	for(auto p : v){
		if(cnt >= n) break;
		
		if(st.count(r[p.second])){
			st.erase(r[p.second]);
		} else {
			for(auto q : st){
				if(q > r[p.second]) break;
				
				adj[r[p.second]].push_back(q);
				adj[q].push_back(r[p.second]);
				cnt++;
				
				if(cnt >= n) break;
			}
			st.insert(r[p.second]);
		}
	}
	
	fill(visited, visited+2*maxN, false);
	
	if(cnt == n-1 && dfs(r[0], r[0]) && cnt2 == n){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
    return 0;
}
