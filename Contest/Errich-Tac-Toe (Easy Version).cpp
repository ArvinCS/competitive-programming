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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		short n;
		cin >> n;
		
		vector<pair<int, int>> colors[3];
		char data[n][n];
		for(short x=0;x<n;x++){
			for(short y=0;y<n;y++){
				cin >> data[x][y];
				
				if(data[x][y] != '.'){
					colors[(x+y)%3].push_back({x,y});
				}
			}
		}
		
		if(colors[0].size() <= colors[1].size() && colors[0].size() <= colors[2].size()){
			for(short x=0;x<colors[0].size();x++){
				data[colors[0][x].first][colors[0][x].second] = 'O';
			}
		} else if(colors[1].size() <= colors[2].size() && colors[1].size() <= colors[0].size()){
			for(short x=0;x<colors[1].size();x++){
				data[colors[1][x].first][colors[1][x].second] = 'O';
			}
		} else {
			for(short x=0;x<colors[2].size();x++){
				data[colors[2][x].first][colors[2][x].second] = 'O';
			}
		}
		
		for(short x=0;x<n;x++){
			for(short y=0;y<n;y++){
				cout << data[x][y];
			}
			cout << "\n";
		}
	}
	
    return 0;
}

