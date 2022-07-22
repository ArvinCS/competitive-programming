#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int m, n;
		cin >> m >> n;
		
		pair<int, int> p[n];
		for(int x=0;x<n;x++){
			cin >> p[x].first >> p[x].second;
		}
		
		bool exist[m+1][m+1];
		fill(exist[0], exist[m], false);
		
		for(int x=0;x<n;x++){
			exist[p[x].first][p[x].second] = true;
		}
		
		vector<vector<pair<int, int>>> ans;
		for(int x=0;x<=m;x++){
			for(int y=0;y<=m;y++){
				if(exist[x][y]){
					for(int i=0;i<=2;i++){
						if(y+i > m) break;
						
						bool valid = true;
						for(int z=y+i;z>=y+i-2;z--){
							if(z < 0){
								valid = false;
								break;
							}
							if(!exist[x][z]) valid = false;
						}
						
						if(valid){
							vector<pair<int, int>> v;
							for(int z=y+i;z>=y+i-2;z--){
								v.push_back({x, z});
							}
							break;
						}
					}
				}
			}
		}
		
		cout << ans.size() << "\n";
	}
	
	return 0;
}
