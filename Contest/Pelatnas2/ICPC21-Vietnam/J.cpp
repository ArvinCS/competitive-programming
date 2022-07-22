#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int c;
	cin >> c;
	
	int a[3][3];
	for(int x=0;x<3;x++){
		for(int y=0;y<3;y++){
			cin >> a[x][y];
		}
	}
	
	vector<tuple<int, int, int, int, int, int>> ans;
	int state[4];
	fill(state, state+4, 0);
	
	vector<tuple<int, int, int>> v;
	if(a[1][1] != a[0][1]){
		int mv = (a[0][1]-a[1][1]+c-1)%c+1;
		
		ans.push_back(make_tuple(0, 0, 0, 1, 9, mv));
		for(int x=1;x<3;x++){
			for(int y=1;y<3;y++){
				a[x][y] += mv;
				a[x][y] %= c;
			}
		}
	}
	
	int mv = (a[1][2] - a[1][1] + c - 1) % c + 1;
	ans.push_back(make_tuple(1, 0, 0, 0, 1, mv));
	for(int x=0;x<2;x++){
		for(int y=0;y<2;y++){
			a[x][y] += mv;
			a[x][y] %= c;
		}
	}
	
	mv = (a[2][1] - a[1][1] + c - 1) % c + 1;
	ans.push_back(make_tuple(0, 1, 0, 0, 3, mv));
	for(int x=0;x<2;x++){
		for(int y=1;y<3;y++){
			a[x][y] += mv;
			a[x][y] %= c;
		}
	}
	
	mv = (a[1][0] - a[1][1] + c - 1) % c + 1;
	ans.push_back(make_tuple(0, 1, 0, 1, 9, mv));
	for(int x=0;x<3;x++){
		for(int y=1;y<3;y++){
			a[x][y] += mv;
			a[x][y] %= c;
		}
	}
	
	ans.push_back(make_tuple(0, 0, 0, 0, 1, (a[1][1] - a[0][0] + c-1)%c + 1));
	ans.push_back(make_tuple(0, 0, 0, 0, 3, (a[1][1] - a[0][2] + c-1)%c + 1));
	ans.push_back(make_tuple(0, 0, 0, 0, 7, (a[1][1] - a[2][0] + c-1)%c + 1));
	ans.push_back(make_tuple(0, 0, 0, 0, 9, (a[1][1] - a[2][2] + c-1)%c + 1));
	
	ans.push_back(make_tuple(1, 1, 1, 1, 1, (0 - a[1][1] + c - 1) % c + 1));
	
	cout << "YES\n";
	cout << ans.size() << "\n";
	for(auto t : ans){
		cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << " " << get<4>(t) << " " << get<5>(t) << "\n";
	}
	return 0;
}
