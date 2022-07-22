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

int a[4] = {1, -1, 0, 0};
int b[4] = {0, 0, 1, -1};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		int r, c;
		cin >> r >> c;
		
		char data[r][c];
		for(int x=0;x<r;x++){
			for(int y=0;y<c;y++){
				cin >> data[x][y];
			}
		}
		
		int dist[r][c];
		fill(dist[0], dist[r], inf_int);
		dist[0][0] = 0;
		
		deque<pair<int, int>> q;
		q.push_front({0, 0});
		while(!q.empty()){
			pair<int, int> p = q.front();
			q.pop_front();
			
			for(int i=0;i<4;i++){
				int curX = p.first+a[i], curY = p.second+b[i];
				if(curX >= 0 && curX < r && curY >= 0 && curY < c){
					if(dist[p.first][p.second]+(data[p.first][p.second] != data[curX][curY]) < dist[p.first+a[i]][p.second+b[i]]){
						dist[p.first+a[i]][p.second+b[i]] = dist[p.first][p.second]+(data[p.first][p.second] != data[curX][curY]);
						
						if(data[p.first][p.second] != data[curX][curY]){
							q.push_back({curX, curY});
						} else {
							q.push_front({curX, curY});
						}
					}
				}
			}
		}
		
		cout << dist[r-1][c-1] << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

