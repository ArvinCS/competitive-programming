#include <iostream>
#include <vector>

using namespace std;

#define inf_int 1e9
#define inf_ll 1e18

int getParent(int x){
	return (x-1)/2;
}

int getLeftChild(int x){
	return 2*x+1;
}

int getRightChild(int x){
	return 2*x+2;
}

vector<pair<short, short>> nodes;

void push(pair<short, short> node){
	nodes.push_back(node);
	
	int i = nodes.size() - 1;
	pair<short, short> tmp;
	while(i > 0 && nodes[i].second < nodes[getParent(i)].second){
		tmp = nodes[i];
		nodes[i] = nodes[getParent(i)];
		nodes[getParent(i)] = tmp;
		i = getParent(i);
	}
}

void pop(){
	nodes[0] = nodes.back();
	nodes.pop_back();
	
	short i = 0;
	bool swapped = true;
	pair<short, short> tmp;
	while(swapped){
		int maxIndex = i;
		if(getLeftChild(i) < nodes.size() && nodes[maxIndex].second > nodes[getLeftChild(i)].second){
			maxIndex = getLeftChild(i);
		}
		if(getRightChild(i) < nodes.size() && nodes[maxIndex].second > nodes[getRightChild(i)].second){
			maxIndex = getRightChild(i);
		}
		tmp = nodes[i];
		nodes[i] = nodes[maxIndex];
		nodes[maxIndex] = tmp;
		swapped = maxIndex != i;
		i = maxIndex;
	}
}

short m, n, q;
	
pair<int, int> findCost(vector<pair<short, short>> adj[], int before, int start, int after){
	bool visited[n+1];
	int dist[n+1];
	for(int x=1;x<=n;x++){
		visited[x] = false;
		dist[x] = (int) inf_int;
	}
	
	dist[start] = 0;
	push({start, (short) 0});
	
//	cout << "-" << before << "-" << start << "-" << after << "\n";
	while(!nodes.empty()){
		pair<short, short> curNode = nodes.front();
		pop();
		
		if(!visited[curNode.first]){
			visited[curNode.first] = true;
			for(int x=0;x<adj[curNode.first].size();x++){
				if(!visited[adj[curNode.first][x].first]){
//					cout << "visit " << adj[curNode.first][x].first << "\n";
					if(dist[adj[curNode.first][x].first] > dist[curNode.first] + adj[curNode.first][x].second){
						dist[adj[curNode.first][x].first] = dist[curNode.first] + adj[curNode.first][x].second;
						push({adj[curNode.first][x].first, dist[adj[curNode.first][x].first]});
					}
				}
			}
		}
	}
	
//	for(int x=1;x<=n;x++) cout << dist[x] << " ";
//	cout << "\n";
	return {dist[before], dist[after]};
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> n >> m >> q;
	
	short u,v,w;
	vector<short> p;
	vector<pair<short, short>> adj[n+1];
	for(short x=1;x<=m;x++){
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	
	for(int x=0;x<q;x++){
		short tmp;
		cin >> tmp;
		p.push_back(tmp);
	}
	
	long long cost = 0;
	for(int x=1;x<q;x+=2){
		nodes.clear();
		int before = p[x-1], start = p[x], after = p[x+1];
		pair<int, int> data = findCost(adj, before, start , x + 1 < q ? after : p[0]);
//		cout << data.first << " " << data.second << "\n";
		cost += data.first;
		if(x+1 < q) cost += data.second;
	}
	
//	long long cost = 0;
//	int i = p.front();
//	p.erase(p.begin());
//	
//	while(!p.empty()){
//		int currentPos = i;
//		int targetPos = p.front();
//
//		if(pred[targetPos] != currentPos){
//			if(step[targetPos] > step[currentPos]){
//				while(step[targetPos] > step[currentPos]){
//					cost += dist[targetPos];
//					cout << " +" << dist[targetPos];
//					targetPos = pred[targetPos];
//				}
//				cost += dist[currentPos];
//				cost += dist[targetPos];
//				cout << " +" << dist[currentPos];
//				cout << " +" << dist[targetPos];
//				i = p.front();
//			} else if(step[targetPos] < step[currentPos]){
//				while(step[targetPos] < step[currentPos]){
//					cost += dist[currentPos];
//					cout << " +" << dist[currentPos];
//					currentPos = pred[currentPos];
//				}
//				cost += dist[currentPos];
//				cost += dist[targetPos];
//				cout << " +" << dist[currentPos];
//				cout << " +" << dist[targetPos];
//				i = currentPos;
//			}
//		} else {
//			cost += dist[targetPos];
//			cout << " +" << dist[targetPos];
//			i = p.front();
//		}
//		p.erase(p.begin());
//	}
//	cout << "\n";
	cout << cost << "\n";
    return 0;
}
