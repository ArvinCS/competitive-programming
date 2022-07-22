#include <iostream>
#include <vector>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
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

vector<pair<us, int>> heap;

void push(pair<us, int> node){
	heap.push_back(node);
	
	pair<us, int> tmp;
	int i = heap.size() - 1;
	while(i > 0 && heap[getParent(i)].second > heap[i].second){
		tmp = heap[getParent(i)];
		heap[getParent(i)] = heap[i];
		heap[i] = tmp;
		
		i = getParent(i);
	}
}

void pop(){
	heap[0] = heap.back();
	heap.pop_back();
	
	pair<us, int> tmp;
	int i = 0;
	bool swapped = true;
	while(swapped){
		int maxIndex = i;
		
		if(getLeftChild(i) < heap.size() && heap[maxIndex].second > heap[getLeftChild(i)].second){
			maxIndex = getLeftChild(i);
		}
		if(getRightChild(i) < heap.size() && heap[maxIndex].second > heap[getRightChild(i)].second){
			maxIndex = getRightChild(i);
		}
		tmp = heap[i];
		heap[i] = heap[maxIndex];
		heap[maxIndex] = tmp;
		
		swapped = i != maxIndex;
		i = maxIndex;
	}
}

int mst(us n, vector<int> cost[]){
	int dist[n];
	bool visited[n];
	us pred[n];
	
	for(us x=0;x<n;x++){
		dist[x] = inf_int;
		visited[x] = false;
		pred[x] = x;
	}
	
	int ans = 0;
	dist[0] = 0;
	push({0, 0});
	
	while(!heap.empty()){
		pair<us, int> node = heap.front();
		pop();
		if(!visited[node.first]){
			visited[node.first] = true;
			ans += dist[node.first];
			
			for(int x=0;x<cost[node.first].size();x++){
				if(x == node.first) continue;
				if(!visited[x] && dist[x] > cost[node.first][x]){
//					cout << node.first << " visit to " << x << "(" << dist[x] << "->" << cost[node.first][x] << ")" << "\n";
					dist[x] = cost[node.first][x];
					pred[x] = node.first;
					push({x, dist[x]});
				}
			}
		}
//		for(int x=0;x<n;x++) cout << dist[x] << " ";
//		cout << "\n";
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us n;
	cin >> n;
	
	int tmp;
	vector<int> cost[n]; // 0 based index
	for(us x=0;x<n;x++){
		for(us i=0;i<n;i++){
			cin >> tmp;
			cost[x].push_back(tmp);
		}
	}
	
	cout << mst(n, cost) << "\n";
    return 0;
}
