#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

long long inf = 1e18;

bool sortEdges(pair<short, short> edge1, pair<short, short> edge2){
	if(edge1.first < edge2.first){
		return true;
	} else if(edge1.first == edge2.first){
		return edge1.second < edge2.second;
	} else {
		return false;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int v,e;
		cin >> v >> e;
		
		vector<pair<int, int>> edges;
		long long weight[v][v], dist[v];
		int pred[v];
		for(int x=0;x<v;x++){
			dist[x] = inf;
			pred[x] = x;
			for(int y=0;y<v;y++) weight[x][y] = inf;
		}
		
		long long c;
		pair<int, int> tmp;
		for(int x=0;x<e;x++){
			cin >> tmp.first >> tmp.second >> c;
			edges.push_back(tmp);
			weight[tmp.first][tmp.second] = min(c, weight[tmp.first][tmp.second]);
		}
		
		dist[0] = 0;
		for(int i=0;i<v-1;i++){
			for(int x=0;x<edges.size();x++){	
				if(dist[edges[x].second] > dist[edges[x].first] + weight[edges[x].first][edges[x].second]){
					dist[edges[x].second] = dist[edges[x].first] + weight[edges[x].first][edges[x].second];
					pred[edges[x].second] = pred[edges[x].first];
				}
			}
		}
		
		bool cycle = false;
		for(int x=0;x<edges.size();x++){
			if(dist[edges[x].second] > dist[edges[x].first] + weight[edges[x].first][edges[x].second] && pred[edges[x].second] == 0){
				cycle = true;
				break;
			}
		}
		
		if(!cycle){
			int root = v-1;
			while(true){
				if(pred[root] == root) break;
				root = pred[root];
			}
			if(root != 0){
				cout << "Tidak ada jalan\n";
			} else {
				cout << dist[v-1] << "\n";
			}
		} else {
			cout << "Pak Dengklek tidak mau pulang\n";
		}
	}
    return 0;
}
