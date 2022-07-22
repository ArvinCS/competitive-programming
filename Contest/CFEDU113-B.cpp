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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		bool must[n];
		fill(must, must+n, false);
		
		vector<int> v[2];
		for(int x=0;x<n;x++){
			v[(s[x] - '1')].push_back(x);
			if(s[x] == '1') must[x] = true;
		}
		
		char ans[n][n];
		fill(ans[0], ans[n], '?');
		
		for(int x=0;x<n;x++){
			bool win = false;
			for(int y=0;y<n;y++){
				if(x == y){
					ans[x][y] = 'X';
					continue;
				}
				
				if(must[x]){
					ans[x][y] = ans[y][x] = '=';
				}
			}
		}
		
		for(int x=0;x<v[1].size();x++){
			int nxt = (x+1)%v[1].size();
			
			ans[v[1][x]][v[1][nxt]] = '+';
			ans[v[1][nxt]][v[1][x]] = '-';
		}
		
		bool valid = true;
		for(int x=0;x<n;x++){
			int win = 0, lose = 0;
			for(int y=0;y<n;y++){
				if(x == y) continue;
				
				if(ans[x][y] == '+'){
					win++;
				} else if(ans[x][y] == '-'){
					lose++;
				} else if(ans[x][y] == '?'){
					ans[x][y] = ans[y][x] = '=';
				}
			}
			
			if(must[x] && lose > 0){
				valid = false;
				break;
			} else if(!must[x] && win == 0){
				valid = false;
				break;
			}
		}
		
		if(!valid){
			cout << "NO\n";
			continue;
		}
		
		cout << "YES\n";
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cout << ans[x][y];
			}
			cout << "\n";
		}
	}
	
    return 0;
}

