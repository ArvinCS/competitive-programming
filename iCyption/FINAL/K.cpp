#include <iostream>

using namespace std;

#define inf_int 1e9
#define inf_ll 1e18

int n;
short matrix[1001][1001];
bool visited[1001][1001];

void dfs(int a, int b){
	if(matrix[a][b] == 0) return;
//	cout << "visited " << a << "," << b << "\n";
	visited[a][b] = true;
	
	for(int x=-1;x<=1;x++){
		for(int y=-1;y<=1;y++){
			if(x == 0 && y == 0) continue;
			if(!visited[a+x][b+y]) dfs(a+x, b+y);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;

	for(int x=1;x<=n;x++){
		for(int y=1;y<=n;y++){
			cin >> matrix[x][y];
			visited[x][y] = false;
		}
	}
	
	int ans = 0;
	for(int x=1;x<=n;x++){
		for(int y=1;y<=n;y++){
			if(!visited[x][y] && matrix[x][y] == 1){
				dfs(x,y);
				ans++;
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}
