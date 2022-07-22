#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int q;
	cin >> q;
	
	while(q--){
		int n;
		string s, t;
		cin >> n;
		cin >> s >> t;
		
		vector<int> v[3], w[3];
		for(int x=0;x<n;x++){
			v[(s[x] - 'a')].push_back(x);
			w[(t[x] - 'a')].push_back(x);
		}
		
		bool possible = true;
		for(int x=0;x<3&&possible;x++){
			if(v[x].size() != w[x].size()){
				possible = false;
				break;
			}
			
			if(x == 0){
				for(int y=0;y<v[x].size();y++){
					if(v[x][y] > w[x][y]){
						possible = false;
						break;
					}
				}
			} else if(x == 2){
				for(int y=0;y<v[x].size();y++){
					if(v[x][y] < w[x][y]){
						possible = false;
						break;
					}
				}
			}
		}
		
		if(!possible){
			cout << "NO\n";
			continue;
		}
		
		vector<pair<int, int>> line;
		for(int y=0;y<v[0].size();y++){
			line.push_back({v[0][y], 1});
			line.push_back({w[0][y]+1, -1});
		}
		for(int y=0;y<v[2].size();y++){
			line.push_back({w[2][y], 2});
			line.push_back({v[2][y]+1, -2});
		}
		
		int a = 0, c = 0;
		sort(line.begin(), line.end());
		
		for(auto &p : line){
			if(p.second == -2){
				c--;
			} else if(p.second == -1){
				a--;
			} else if(p.second == 1){
				a++;
			} else if(p.second == 2){
				c++;
			}
			
			if(a != 0 && c != 0){
				possible = false;
				break;
			}
		}
		
		cout << (possible ? "YES" : "NO") << "\n";
	}
    return 0;
}

