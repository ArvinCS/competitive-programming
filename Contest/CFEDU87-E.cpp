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

const int maxN = 5e3 + 5;

vector<int> adj[maxN];
vector<int> v[maxN];
bool visited[maxN];
int color[maxN], cnt[maxN], idx = 0;
bool table[maxN][maxN];

bool dfs(int curNode){
	v[idx].push_back(curNode);
	cnt[idx] += color[curNode];
	visited[curNode] = true;
	
	for(auto nxt : adj[curNode]){
		if(!visited[nxt]){
			color[nxt] = color[curNode]^1;
			if(!dfs(nxt)){
				return false;
			}
		} else {
			if(color[nxt] == color[curNode]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	// Observations:
	// Color each graph alternating 0 and 1.
	// Color 2 always in parity of 0 or 1 (not both).
	// Graph isn't guaranteed all connected
	// Each component, dp subsetsum pick 0 / 1 parity to make equal to n2
	// Color each component based of it's parity, if it's picked for n2 then color it 2, otherwise color it 1/3 that still available.
	
	int n, m;
	cin >> n >> m;
	
	int must[3];
	for(int x=0;x<3;x++) cin >> must[x];
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	fill(visited, visited+maxN, false);
	fill(color, color+maxN, -1);
	fill(table[0], table[maxN], false);
	fill(cnt, cnt+maxN, 0);
	
	table[0][0] = true;
	for(int x=0;x<n;x++){
		if(!visited[x]){
			color[x] = 0;
			if(!dfs(x)){
				cout << "NO\n";
				return 0;
			}
			
			int one = cnt[idx];
			int zero = v[idx].size()-one;
			
			for(int y=0;y<maxN;y++){
				if(y+one < maxN){
					table[idx+1][y+one] |= table[idx][y];
				}
				if(y+zero < maxN){
					table[idx+1][y+zero] |= table[idx][y];
				}
			}
			idx++;
		}
	}
	
	if(!table[idx][must[1]]){
		cout << "NO\n";
		return 0;
	}
	
	int ans[n];
	vector<int> backtrack;
	int cur = must[1];
	for(int x=idx;x>0;x--){
		int one = cnt[x-1];
		int zero = v[x-1].size()-one;
		
		if(cur-one >= 0 && table[x-1][cur-one]){
			backtrack.push_back(1);
			cur -= one;
		} else if(cur-zero >= 0 && table[x-1][cur-zero]){
			backtrack.push_back(0);
			cur -= zero;
		}
	}
	
	reverse(backtrack.begin(), backtrack.end());
	
	for(int x=0;x<backtrack.size();x++){
		for(auto node : v[x]){
			if(color[node] == backtrack[x]){
				ans[node] = 2;
				must[1]--;
			} else {
				if(must[0] > 0){
					ans[node] = 1;
					must[0]--;
				} else if(must[2] > 0){
					ans[node] = 3;
					must[2]--;
				}
			}
		}
	}
	
	cout << "YES\n";
	for(int x=0;x<n;x++){
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

