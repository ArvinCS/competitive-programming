#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	auto getDist = [&](int i, int j) -> int {
		return abs(p[i].first-p[j].first)+abs(p[i].second-p[j].second);
	};
	
	bool same[n][n][n];
	fill(*same[0], *same[n], false);
	
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(x == y) continue;
			for(int z=0;z<n;z++){
				if(x == z || y == z) continue;
				
				if(getDist(x, y) == getDist(x, z) && getDist(x, y) == getDist(y, z)){
					same[x][y][z] = true;
					cout << x << " " << y << " " << z << "\n";
				}
			}
		}
	}
	
	// d(a,b) < d(a,c) && d(a,b) < d(b,c)
	// d(a,b) < d(a,b) + 
    return 0;
}

