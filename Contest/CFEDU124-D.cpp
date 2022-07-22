#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxXY = 2e5 + 5;

int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, 1, -1};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	map<pair<int, int>, int> mp;
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
		mp[p[x]] = x;
	}
	
	queue<pair<int, int>> q;
	bool visited[n];
	pair<int, int> ans[n];
	int dist[n];
	fill(dist, dist+n, 1e9);
	
	for(int x=0;x<n;x++){
		bool found = false;
		for(int i=0;i<4;i++){
			int newX = p[x].first+moveX[i], newY = p[x].second+moveY[i];
			
			auto it = mp.find({newX, newY});
			if(it == mp.end()){
				dist[x] = 1;
				ans[x] = {newX, newY};
				found = true;
				break;
			}
		}
		
		if(found){
			q.push(p[x]);
		}
	}
	
	while(!q.empty()){
		pair<int, int> cur = q.front();
		q.pop();
		
		int idx = mp[cur];
		
		for(int i=0;i<4;i++){
			int newX = cur.first+moveX[i], newY = cur.second+moveY[i];
			
			auto it = mp.find({newX, newY});
			if(it != mp.end() && dist[(*it).second] > dist[idx]+1){
				dist[(*it).second] = dist[idx]+1;
				ans[(*it).second] = ans[idx];
				q.push({newX, newY});
			}
		}
	}
	
	for(int x=0;x<n;x++){
		cout << ans[x].first << " " << ans[x].second << "\n";
	}
    return 0;
}

