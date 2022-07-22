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

bool segment(pair<int, int> a, pair<int, int> b, pair<int, int> c){
	return (b.first <= max(a.first, c.first) && b.first >= min(a.first, c.first) && b.second <= max(a.second, c.second) && b.second >= min(a.second, c.second));
}

int orientation(pair<int, int> a, pair<int, int> b, pair<int, int> c){
	int val = (b.second - a.second) * (c.first - b.first) - (b.first - a.first) * (c.second - b.second);
	
	if(val == 0) return 0;
	
	return (val >= 0) ? 1 : 2;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int x[2], y[2];
		cin >> x[0] >> y[0] >> x[1] >> y[1];
		
		pair<int, int> line[2];
		cin >> line[0].first >> line[0].second >> line[1].first >> line[1].second;
		
		vector<pair<int, int>> points;
		for(int a=0;a<2;a++){
			for(int b=0;b<2;b++){
				points.push_back({x[a], y[b]});
			}
		}		
		
		sort(line, line+2);
		sort(points.begin(), points.end());
		
		bool possible = false;
		for(int i=0;i<points.size()-1;i++){
			for(int j=i+1;j<points.size();j++){
				if(points[i].first != points[j].first && points[i].second != points[j].second) continue;
				
				int a = orientation(line[0], line[1], points[i]);
				int b = orientation(line[0], line[1], points[j]);
				int c = orientation(points[i], points[j], line[0]);
				int d = orientation(points[i], points[j], line[1]);
				
				if(a != b && c != d){
					possible = true;
				}
				
				if(a == 0 && segment(line[0], points[i], line[1])){
					possible = true;
				}
				if(b == 0 && segment(line[0], points[j], line[1])){
					possible = true;
				}
				if(c == 0 && segment(points[i], line[0], points[j])){
					possible = true;
				}
				if(d == 0 && segment(points[i], line[1], points[j])){
					possible = true;
				}
			}
		}
		
		if(possible) cout << "YA\n";
		else cout << "TIDAK\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

