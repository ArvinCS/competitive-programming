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
int a[maxN], b[maxN], c[maxN];

bool customSort(int idx1, int idx2){
	return c[idx1] > c[idx2];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m, k;
	cin >> n >> m >> k;
	
	int last[n];
	for(int x=0;x<n;x++){
		cin >> a[x] >> b[x] >> c[x];
		last[x] = x;
	}
	
	for(int x=0;x<m;x++){
		int u, v;
		cin >> u >> v;
		
		u--; v--;
		last[v] = max(last[v], u);
	}
	
	bool valid = true;
	int sum = k;
	for(int x=0;x<n;x++){
		if(sum < a[x]){
			valid = false;
			break;
		}
		sum += b[x];
	}
	
	if(!valid){
		cout << "-1\n";
		return 0;
	}
	
	for(int x=0;x<n;x++){
		adj[last[x]].push_back(x);
	}
	for(int x=0;x<n;x++){
		sort(adj[x].begin(), adj[x].end(), customSort);
	}
	
	int table[n+1][5005];
	fill(table[0], table[n+1], -1e9);
	
	table[0][k] = 0;
	for(int x=0;x<n;x++){
		for(int y=a[x]+b[x];y<=5000;y++){
			table[x+1][y] = max(table[x+1][y], table[x][y-b[x]]);
		}
		
		int cur = 0;
		for(int z=0;z<adj[x].size();z++){
			cur += c[adj[x][z]];
			for(int y=max(z+1, a[x]+b[x]);y<=5000;y++){
				table[x+1][y-z-1] = max(table[x+1][y-z-1], table[x][y-b[x]]+cur);
			}
		}
	}
	
	int ans = 0;
	for(int x=0;x<=5000;x++){
		ans = max(ans, table[n][x]);
	}
	
	cout << ans << "\n";
    return 0;
}

