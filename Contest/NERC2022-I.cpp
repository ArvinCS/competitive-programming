#include <bits/stdc++.h>

using namespace std;

#define ll long long

map<pair<int, int>, int> mp;

int scan(int r, int c){
	cout << "SCAN " << r << " " << c << endl;
	
	int res;
	cin >> res;
	
	return res;
}

int dig(int r, int c){
	if(mp.count({r, c})) return mp[{r, c}];
	
	cout << "DIG " << r << " " << c << endl;
	
	int res;
	cin >> res;
	
	return mp[{r, c}] = (res == 1 ? 2 : 0);
}

int simulate(int r, int c, int r2, int c2){
	return abs(r-r2) + abs(c-c2);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		mp.clear();
		
		set<pair<int, int>> st;
		vector<pair<int, int>> p;
		while(p.size() < 5){
			int x = rng() % n + 1;
			int y = rng() % m + 1;
			
			while(st.count({x, y})){
				x = rng() % n + 1;
				y = rng() % m + 1;
			}
			
			p.push_back({x, y});
		}
		
		int res[5];
		for(int x=0;x<p.size();x++){
			res[x] = scan(p[x].first, p[x].second);
		}
		
		for(int x1=1;x1<=n;x1++){
			for(int y1=1;y1<=m;y1++){
				for(int x2=x1;x2<=n;x2++){
					for(int y2=(x2 == x1 ? y1+1 : 1);y2<=m;y2++){
						bool valid = true;
						for(int x=0;x<p.size();x++){
							if(res[x] != simulate(p[x].first, p[x].second, x1, y1)+simulate(p[x].first, p[x].second, x2, y2)){
								valid = false;
							}
						}
						
						if(valid){
							dig(x1, y1);
							dig(x2, y2);
						}
					}
				}
			}
		}
	}
	
    return 0;
}

