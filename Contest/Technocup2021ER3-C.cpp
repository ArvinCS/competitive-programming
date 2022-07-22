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

const int maxN = 55;

int n, m;
char grid[maxN][maxN];
bool possible[maxN][maxN];
bool visited[maxN][maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		cin >> n >> m;
		
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				cin >> grid[x][y];
			}
		}
		
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(grid[x][y] == 'B'){
					if(x-1>=0 && grid[x-1][y] == '.') grid[x-1][y] = '#';
					if(x+1<n && grid[x+1][y] == '.') grid[x+1][y] = '#';
					if(y-1>=0 && grid[x][y-1] == '.') grid[x][y-1] = '#';
					if(y+1<m && grid[x][y+1] == '.') grid[x][y+1] = '#';
				}
			}
		}
		
		fill(possible[0], possible[maxN], false);
		fill(visited[0], visited[maxN], false);
		
		bool valid = true;
		
		queue<pair<int, int>> q;
		q.push({n-1, m-1});
		
		visited[n-1][m-1] = true;
		while(!q.empty()){
			pair<int, int> p = q.front();
			q.pop();
			
			if(grid[p.first][p.second] == '#') continue;
			
			possible[p.first][p.second] = true;
			
			if(p.first-1 >= 0 && !visited[p.first-1][p.second] && grid[p.first-1][p.second] != '#'){
				visited[p.first-1][p.second] = true;
				q.push({p.first-1, p.second});
			}
			if(p.first+1 < n && !visited[p.first+1][p.second] && grid[p.first+1][p.second] != '#'){
				visited[p.first+1][p.second] = true;
				q.push({p.first+1, p.second});
			}
			if(p.second-1 >= 0 && !visited[p.first][p.second-1] && grid[p.first][p.second-1] != '#'){
				visited[p.first][p.second-1] = true;
				q.push({p.first, p.second-1});
			}
			if(p.second+1 < m && !visited[p.first][p.second+1] && grid[p.first][p.second+1] != '#'){
				visited[p.first][p.second+1] = true;
				q.push({p.first, p.second+1});
			}
		}
		
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(grid[x][y] == 'G'){
					if(!possible[x][y]){
						valid = false;
						break;
					}
				}
			}
		}
		
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(grid[x][y] == 'B'){
					if(possible[x][y]){
						valid = false;
						break;
					}
				}
			}
		}
		
		if(valid) cout << "Yes\n";
		else cout << "No\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

