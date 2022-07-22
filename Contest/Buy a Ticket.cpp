#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

const ull mxN = 200005;

ull n, concert[mxN];
vector<pair<ull, ui>> adj[mxN];

void search(){
	priority_queue<pair<ull, ui>, vector<pair<ull, ui>>, greater<pair<ull, ui>>> q;
	ull dist[n];
	for(ui x=0;x<n;x++){
		dist[x] = concert[x];
		q.push({concert[x], x});	
	}
	
	while(!q.empty()){
		pair<ull, ui> node = q.top();
		q.pop();
		
		if(node.first > dist[node.second]) continue;
		for(ui y=0;y<adj[node.second].size();y++){
			pair<ull, ui> targetNode = adj[node.second][y];
			ull tmp = 2*targetNode.first + node.first;
			if(dist[targetNode.second] > tmp){
				dist[targetNode.second] = tmp;
				q.push({dist[targetNode.second], targetNode.second});
			}
//			cout << node.second << " to " << targetNode.second << " -> " << dist[targetNode.second] << "\n";
		}
	}
	
	cout << dist[0];
	for(ui x=1;x<n;x++){
		cout << " " << dist[x];
	}
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ull m;
	cin >> n >> m;
		
	for(ui x=0;x<m;x++){
		ull tmp1, tmp2, tmp3;
		cin >> tmp1 >> tmp2 >> tmp3;
		
		adj[tmp1-1].push_back({tmp3, tmp2-1});
		adj[tmp2-1].push_back({tmp3, tmp1-1});
	}
	
	for(ui x=0;x<n;x++){
		cin >> concert[x];
	}
	
	search();
    return 0;
}

