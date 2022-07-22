#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int h, w, n;
	cin >> h >> w >> n;
	
	int sx, sy;
	cin >> sx >> sy;
	
	int gx, gy;
	cin >> gx >> gy;
	
	set<pa
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	pq.push(make_tuple(abs(gx-sx)+abs(gy-sy), sx, sy));
	
	while(!pq.empty()){
		tuple<int, int, int> t = pq.top();
		pq.pop();
		
		int dist = get<0>(t);
		int posx = get<1>(t), posy = get<2>(t);
		
	}
    return 0;
}

