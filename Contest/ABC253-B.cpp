#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int h, w;
	cin >> h >> w;
	
	string s[h];
	for(int x=0;x<h;x++){
		cin >> s[x];
	}
	
	vector<pair<int, int>> v;
	for(int x=0;x<h;x++){
		for(int y=0;y<w;y++){
			if(s[x][y] == 'o'){
				v.push_back({x, y});
			}
		}
	}
	
	cout << abs(v[0].first-v[1].first)+abs(v[0].second-v[1].second) << "\n";
    return 0;
}

