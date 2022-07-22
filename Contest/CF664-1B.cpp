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

int n, m, k, deg[maxN], cnt[maxN];
tuple<int, int, int> edge[maxN];
vector<pair<int, int>> adj[maxN];
bool valid[10][10][10][10];

int solve(int idx, int c[]){
	if(idx == k){
		bool ok = true;
		
		for(int x=0;x<k;x++){
			for(int y=x;y<k;y++){
				if(!valid[x][c[x]][y][c[y]]){
					ok = false;
				}
			}
		}
		
		return ok;
	}
	
	int ans = 0;
	for(int x=0;x<=idx;x++){
		c[idx] = x;
		ans += solve(idx+1, c);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n >> m >> k;
	
	fill(deg, deg+n, 0);
	fill(**valid[0], **valid[10], true);
	fill(cnt, cnt+n, 0);
	
	for(int x=0;x<m;x++){
		int a, b, w;
		cin >> a >> b >> w;
		
		a--; b--;
		edge[x] = make_tuple(w, a, b);
		deg[a]++;
	}
		
	sort(edge, edge+m);
	
	for(int x=0;x<m;x++){
		adj[get<2>(edge[x])].push_back({deg[get<1>(edge[x])]-1, cnt[get<1>(edge[x])]});
		cnt[get<1>(edge[x])]++;	
	}
	
	bool exist[k][k];
	for(int x=0;x<n;x++){
		fill(exist[0], exist[k], false);
		
		for(int y=0;y<adj[x].size();y++){
			if(exist[adj[x][y].first][adj[x][y].second]) valid[adj[x][y].first][adj[x][y].second][adj[x][y].first][adj[x][y].second] = false;
			exist[adj[x][y].first][adj[x][y].second] = true;
		}
		
		for(int a=0;a<k;a++){
			for(int b=0;b<=a;b++){
				for(int c=a;c<k;c++){
					for(int d=0;d<=c;d++){
						if(a == c && b == d) continue;
						
						if(exist[a][b] && exist[c][d]){
							valid[a][b][c][d] = false;
						}
					}
				}
			}
		}
	}
	
	int c[k];
	cout << solve(0, c) << "\n";
    return 0;
}

