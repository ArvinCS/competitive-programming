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

const int maxN = 1005;
char label[maxN][maxN];

bool palindrome(string s){
	int length = s.length();
	bool ans = true;
	for(int x=0;x<length/2;x++){
		if(s[x] != s[length-1-x]){
			ans = false;
			break;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cin >> label[x][y];
			}
		}	
		
		bool possible = false;
		vector<int> ans;
		if(m&1){
			possible = true;
			for(int x=1;x<=m+1;x++){
				if(x&1) ans.push_back(1);
				else ans.push_back(2);
			}
		} else {
			for(int x=0;x<n;x++){
				for(int y=0;y<n;y++){
					if(x == y) continue;
					if(label[x][y] == label[y][x]){
						possible = true;
						for(int i=1;i<=m+1;i++){
							if(i&1) ans.push_back(x+1);
							else ans.push_back(y+1);
						}
						break;
					}
				}
				if(possible) break;
			}
			
			if(!possible && n >= 2){
				vector<int> adj[n][2];
				for(int x=0;x<n;x++){
					for(int y=0;y<n;y++){
						if(x == y) continue;
						adj[y][label[x][y]-'a'].push_back(x);
					}
				}
				if(m % 4 == 0){
					for(int y=0;y<n;y++){
						for(int z=0;z<n;z++){
							if(y == z) continue;
							if(adj[y][label[y][z] - 'a'].size() > 0){
								int step[4] = {y+1, z+1, y+1, adj[y][label[y][z]-'a'].front()+1};
						
								int cnt = 0;
								possible = true;
								for(int x=1;x<=m+1;x++){
									ans.push_back(step[cnt++]);
									
									cnt %= 4;
								}
								break;
							}
						}
						if(possible) break;
					}
				} else {
					for(int y=0;y<n;y++){
						for(int z=0;z<n;z++){
							if(y == z) continue;
							if(adj[y][label[y][z] - 'a'].size() > 0){
								int step[4] = {adj[y][label[y][z]-'a'].front()+1, y+1, z+1, y+1};
						
								int cnt = 0;
								possible = true;
								for(int x=1;x<=m+1;x++){
									ans.push_back(step[cnt++]);
									
									cnt %= 4;
								}
								break;
							}
						}
						if(possible) break;
					}
				}
			}
		}
		
		if(possible){
			cout << "YES\n";
			for(int x=0;x<ans.size();x++){
				if(x > 0) cout << " ";
				cout << ans[x];
			}
			cout << "\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

