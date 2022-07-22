#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

const int mxN = 100005;

vector<pair<ull, ui>> adj[mxN];
ui n, k;

struct Edge {
	ull maxCost, currentCost;
	ui index;
	unordered_set<ui> visited;
};

class Compare {
	public:
	bool operator()(Edge a, Edge b){
		if(a.maxCost == b.maxCost) return a.currentCost > b.currentCost;
		return a.maxCost > b.maxCost;
	}
};

// maybe tle
ull search(ui from, ui to){
	priority_queue<Edge, vector<Edge>, Compare> q;
	Edge tmp;
	tmp.index = from;
	tmp.maxCost = tmp.currentCost = 0;
	tmp.visited.insert(from);
	q.push(tmp);
	
	ull distMax[n];
	fill(distMax, distMax+n, inf_ll);
	
	while(!q.empty()){
		Edge node = q.top();
		q.pop();
		
		if(node.index == to){
			return node.maxCost;
		}
		if(node.index < k){
			node.currentCost = 0;
		}
		
		if(node.maxCost > distMax[node.index]) continue;
		cout << node.index << " with cur_cost " << node.currentCost << " (" << distMax[node.index] << ")\n";
		for(ui x=0;x<adj[node.index].size();x++){
			pair<ull, ui> targetNode = adj[node.index][x];
			if(targetNode.second < k && node.visited.count(targetNode.second)) continue;
			cout << "to " << targetNode.second << " (" << distMax[targetNode.second] << ")\n";
			
			Edge tmp = node;
			tmp.index = targetNode.second;
			tmp.currentCost += targetNode.first;
			tmp.maxCost = max(tmp.maxCost, tmp.currentCost);
			tmp.visited.insert(targetNode.second);
			
			if(tmp.maxCost > distMax[targetNode.second]) continue;
			q.push(tmp);
			
			distMax[targetNode.second] = tmp.maxCost;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ui m, q;
	cin >> n >> m >> k >> q;
	
	while(m--){
		ui tmp1, tmp2;
		ull tmp3;
		cin >> tmp1 >> tmp2 >> tmp3;
		
		tmp1--, tmp2--;
		adj[tmp1].push_back({tmp3, tmp2});
		adj[tmp2].push_back({tmp3, tmp1});
	}
	
	while(q--){
		ui tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		
		cout << search(tmp1-1, tmp2-1) << "\n";
	}
	
    return 0;
}

