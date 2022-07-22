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

const int maxN = 1e3 + 5;

pair<int, int> grid[maxN][maxN];
bool visited[maxN][maxN];
int moveX[4] = {1, 0, -1, 0};
int moveY[4] = {0, 1, 0, -1};
char ans[maxN][maxN];
bool cycle[maxN][maxN];
int n;

char convert(int i){
	if(i == 0) return 'U';
	else if(i == 1) return 'L';
	else if(i == 2) return 'D';
	else if(i == 3) return 'R';
	return '?';
}

char convert2(int i){
	if(i == 0) return 'D';
	else if(i == 1) return 'R';
	else if(i == 2) return 'U';
	else if(i == 3) return 'L';
	return '?';
}

void dfs(int curX, int curY, pair<int, int> p){
	visited[curX][curY] = true;		
	
	for(int i=0;i<4;i++){
		int newX = curX+moveX[i], newY = curY+moveY[i];
		if(newX < n && newY < n && newX >= 0 && newY >= 0){
			if(!visited[newX][newY] && grid[newX][newY] == p){
				ans[newX][newY] = convert(i);
				dfs(newX, newY, p);
			}
		}
	}	
}

void dfs2(int curX, int curY, int i){
	visited[curX][curY] = true;
	cycle[curX][curY] = true;
	
	int newX = curX+moveX[i], newY = curY+moveY[i];
	if(newX < n && newY < n && newX >= 0 && newY >= 0){
		if(visited[newX][newY] && cycle[newX][newY]){
			ans[curX][curY] = convert2(i);
			return;
		} else if(!visited[newX][newY] && grid[newX][newY] == make_pair(-2, -2)){
			ans[curX][curY] = convert(i);
			dfs2(newX, newY, i);
			return;
		}
	}
	
	for(int j=(i+1)%4;j!=i;j++, j %= 4){
		newX = curX+moveX[j], newY = curY+moveY[j];
		if(newX < n && newY < n && newX >= 0 && newY >= 0){
			if(visited[newX][newY] && cycle[newX][newY]){
				ans[curX][curY] = convert2(j);
				return;
			} else if(!visited[newX][newY] && grid[newX][newY] == make_pair(-2, -2)){
				ans[curX][curY] = convert2(j);
				dfs2(newX, newY, j);
				return;
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

	cin >> n;
	
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cin >> grid[x][y].first >> grid[x][y].second;
			grid[x][y].first--; grid[x][y].second--;
		}
	}
	
	fill(ans[0], ans[n], '?');
	fill(visited[0], visited[n], false);
	fill(cycle[0], cycle[n], false);
	
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(grid[x][y].first == x && grid[x][y].second == y){
				ans[x][y] = 'X';
				dfs(x, y, grid[x][y]);
			}
		}
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(x+1 < n && !visited[x][y] && !visited[x+1][y] && grid[x][y] == make_pair(-2, -2) && grid[x+1][y] == make_pair(-2, -2)){
				visited[x][y] = visited[x+1][y] = true;
				cycle[x][y] = cycle[x+1][y] = true;
				ans[x][y] = 'D';
				ans[x+1][y] = 'U';
			}
			if(y+1 < n && !visited[x][y] && !visited[x][y+1] && grid[x][y] == make_pair(-2, -2) && grid[x][y+1] == make_pair(-2, -2)){
				visited[x][y] = visited[x][y+1] = true;
				cycle[x][y] = cycle[x][y+1] = true;
				ans[x][y] = 'R';
				ans[x][y+1] = 'L';
			}
		}
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(!visited[x][y] && grid[x][y] == make_pair(-2, -2)){
				dfs2(x, y, 0);
			}
		}
	}
	
	bool valid = true;
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(ans[x][y] == '?'){
				valid = false;
			}
		}
	}
	
	if(valid){
		cout << "VALID\n";
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cout << ans[x][y];
			}
			cout << "\n";
		}
	} else {
		cout << "INVALID\n";
	}
    return 0;
}

