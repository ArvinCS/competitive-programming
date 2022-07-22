#include <iostream>
#include <vector>

using namespace std;

int inf = 1e9;

int getParent(int x){
	return (x-1)/2;
}

int getLeftChild(int x){
	return 2*x+1;
}

int getRightChild(int x){
	return 2*x+2;
}

vector<pair<int, unsigned long long>> nodes;

void push(pair<int, unsigned long long> node){
	nodes.push_back(node);
	
	int i = nodes.size() - 1;
	pair<int, unsigned long long> tmp;
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
	
	int i = 0;
	bool swapped = true;
	pair<int, unsigned long long> tmp;
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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	unsigned short v,e,a,b;
	cin >> v >> e >> a >> b;
	
	vector<int> adj[v+1];
	int weight[v+1][v+1];
	unsigned long long dist[v+1];
	bool visited[v+1];
	
	for(int x=1;x<=v;x++){
		dist[x] = inf;
		visited[x] = false;
	}
	
	short x,y,z;
	while(e--){
		cin >> x >> y >> z;
		adj[x].push_back(y);
		adj[y].push_back(x);
		weight[x][y] = z;
		weight[y][x] = z;
	}
	
	nodes.push_back({a, 0});
	dist[a] = 0;
	while(!nodes.empty()){
		pair<int, unsigned long long> curNode = nodes.front();
		pop();
		
		if(!visited[curNode.first]){
			visited[curNode.first] = true;
			for(int x=0;x<adj[curNode.first].size();x++){
				if(dist[adj[curNode.first][x]] > dist[curNode.first] + weight[curNode.first][adj[curNode.first][x]]){
					dist[adj[curNode.first][x]] = dist[curNode.first] + weight[curNode.first][adj[curNode.first][x]];
					push({adj[curNode.first][x], dist[adj[curNode.first][x]]});
				}
			}
		}
	}
	
	cout << dist[b] << "\n";
    return 0;
}
