#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int dist[100][100];
	fill(dist[0], dist[100], 1e9);
	
	dist[0][0] = 0;
	
	priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
	pq.push({0, 0, 0});
	
	while(!pq.empty()){
		array<int, 3> p = pq.top();
		pq.pop();
		
		if(dist[p[1]][p[2]] < p[0]) continue;
		for(int x=0;x<=60;x++){
			for(int y=0;y<=60;y++){
				ll sum = (x-p[1])*(x-p[1])+(y-p[2])*(y-p[2]);
				
				if(ceil(sqrt(sum)) == floor(sqrt(sum)) && dist[x][y] > p[0]+1){
					dist[x][y] = p[0]+1;
					pq.push({dist[x][y], x, y});
				}
			}
		}
	}
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		cout << dist[n][m] << "\n";
	}
	
    return 0;
}

