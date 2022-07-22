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

const int maxN = 2005;

pair<ll, ll> mv[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
ll grid[maxN][maxN];
ll dist[2][maxN][maxN]; // 0 home 1 school
int n, m;
ll w;

void travel(int id, int startX, int startY){
	queue<tuple<ll, int, int>> q;
	dist[id][startX][startY] = 0;
	q.push(make_tuple(dist[id][startX][startY], startX, startY));
	
	while(!q.empty()){
		tuple<ll, int, int> t = q.front();
		q.pop();
		
		int x = get<1>(t), y = get<2>(t);
		ll cost = get<0>(t);
		
		for(int i=0;i<4;i++){
			if(x+mv[i].first < 0 || x+mv[i].first >= n || y+mv[i].second < 0 || y+mv[i].second >= m) continue;
			
			if(grid[x+mv[i].first][y+mv[i].second] >= 0 && dist[id][x+mv[i].first][y+mv[i].second] > cost+w){
				dist[id][x+mv[i].first][y+mv[i].second] = cost+w;
				q.push(make_tuple(dist[id][x+mv[i].first][y+mv[i].second], x+mv[i].first, y+mv[i].second));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n >> m >> w;
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> grid[x][y];
		}
	}
	
	fill(*dist[0], *dist[2], inf_ll);
	
	travel(0, 0, 0);
	travel(1, n-1, m-1);
	
	ll ans = dist[0][n-1][m-1], ans2 = inf_ll, ans3 = inf_ll; // 2 for cheapest portal from home, 3 school
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(grid[x][y] <= 0) continue;
			
			if(dist[0][x][y] >= 0){
				ans2 = min(ans2, dist[0][x][y] + grid[x][y]);
			}
			if(dist[1][x][y] >= 0){
				ans3 = min(ans3, dist[1][x][y] + grid[x][y]);
			}
		}
	}
	
	ans = min(ans, ans2+ans3); // now combine which better
	
	cout << (ans >= 1e17 ? -1 : ans) << "\n";
    return 0;
}

