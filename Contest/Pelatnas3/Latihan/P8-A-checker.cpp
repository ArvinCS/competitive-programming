#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 3e5 + 5;

int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, 1, -1};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ifstream fin("input_file.txt", ifstream::in);
    ifstream ans("myAnswer.txt", ifstream::in);
	
	int t;
	fin >> t;
	
	while(t--){
		int n, m, b, w;
		fin >> n >> m >> b >> w;
		
		cout << n << " " << m << " " << b << " " << w << "\n";
		char grid[4*n][4*m];
		
		int cnt = b+w;
		int r = -1, col = -1;
		for(int x=0;x<4*n;x++){
			for(int y=0;y<4*m;y++){
				char c;
				ans >> c;
				
				grid[x][y] = c;
				if(c == 'B'){
					if((x+y)%2 == 1){
						cout << "WRONG PLACE AT " << x << " " << y << "\n";
						cout << n << " " << m << " " << b << " " << w << "\n";
						return -1;
					}
					
					r = x; col = y;
					b--;
				} else if(c == 'W'){
					if((x+y)%2 == 0){
						cout << "WRONG PLACE AT " << x << " " << y << "\n";
						cout << n << " " << m << " " << b << " " << w << "\n";
						return -1;
					}
					
					w--;
				}
				cout << c;
			}
			cout << "\n";
		}
		
		queue<pair<int, int>> q;
		bool visited[4*n][4*m];
		fill(visited[0], visited[4*n], false);
		
		visited[r][col] = true;
		q.push({r, col});
		while(!q.empty()){
			pair<int, int> p = q.front();
			q.pop();
			
			cnt--;
			for(int x=0;x<4;x++){
				int newX = p.first+moveX[x], newY = p.second+moveY[x];
				if(newX >= 0 && newY >= 0 && newX < 4*n && newY < 4*m && grid[newX][newY] != '.' && !visited[newX][newY]){
					visited[newX][newY] = true;
					q.push({newX, newY});
				}
			}
		}
		
		if(cnt != 0){
			cout << "NOT CONNECTED\n";
			cout << n << " " << m << " " << b << " " << w << " " << cnt << "\n";
			return -1;
		}
		if(b != 0){
			cout << "BLACK NOT ZERO\n";
			cout << n << " " << m << " " << b << " " << w << "\n";
			return -1;
		}
		if(w != 0){
			cout << "WHITE NOT ZERO\n";
			cout << n << " " << m << " " << b << " " << w << "\n";
			return -1;
		}
		
		cout << "OK\n";
	}
	
    return 0;
}

