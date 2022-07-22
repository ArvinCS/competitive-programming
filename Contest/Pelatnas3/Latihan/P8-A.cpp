#include <bits/stdc++.h>

using namespace std;

#define ll long long

char ans[250][250];
int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, 1, -1};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		int b, w;
		cin >> n >> m >> b >> w;
		
		fill(ans[0], ans[4*n], '.');
		
		bool emptyB = (b == 0);
		for(int y=1;y<4*m;y++){
			if(y%2 == 1){
				if(y+1 < 4*m && b > 0){
					ans[1][y] = 'B';
					b--;
				} else {
					break;
				}
			} else {
				if(w > 0){
					ans[1][y] = 'W';
					w--;
				} else {
					break;
				}
			}
		}
			
		for(int y=1;y<4*m;y+=4){
			for(int x=3;x<4*n;x+=2){
				if(w > 0){
					if(ans[x-2][y] != 'B'){
						break;
					}
					
					ans[x-1][y] = 'W';
					w--;
				} else {
					break;
				}
				if(b == 0){
					break;
				}
				
				if(x+1 >= 4*n) break;
				
				ans[x][y] = 'B';
				b--;
			}
		}
		
		while(b > 0 || w > 0){
			bool ok = false;
			for(int x=4*n-1;x>=0;x--){
				if(b == 0) break;
				for(int y=0;y<4*m;y++){
					if(b == 0) break;
					if(ans[x][y] != '.' || (x+y)%2 == 1) continue;
					
					bool valid = false;
					if(x > 0) valid |= (ans[x-1][y] == 'W');
					if(y > 0) valid |= (ans[x][y-1] == 'W');
					if(x+1 < 4*n) valid |= (ans[x+1][y] == 'W');
					if(y+1 < 4*m) valid |= (ans[x][y+1] == 'W');
					
					if(valid){
						ans[x][y] = 'B';
						b--;
						ok = true;
					}
				}
			}
			for(int x=4*n-1;x>=0;x--){
				if(w == 0) break;
				for(int y=0;y<4*m;y++){
					if(w == 0) break;
					if(ans[x][y] != '.' || (x+y)%2 == 0) continue;
					
					bool valid = emptyB;
					if(x > 0) valid |= (ans[x-1][y] == 'B');
					if(y > 0) valid |= (ans[x][y-1] == 'B');
					if(x+1 < 4*n) valid |= (ans[x+1][y] == 'B');
					if(y+1 < 4*m) valid |= (ans[x][y+1] == 'B');
					
					if(valid){
						ans[x][y] = 'W';
						w--;
						ok = true;
					}
				}
			}
			if(!ok) break;
		}
	
//		cerr << b << " " << w << "\n";
		for(int x=0;x<4*n;x++){
			for(int y=0;y<4*m;y++){
				cout << ans[x][y];
			}
			cout << "\n";
		}
	}
	
    return 0;
}

