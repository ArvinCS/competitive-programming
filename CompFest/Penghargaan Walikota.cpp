#include <iostream>
#include <vector>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

vector<pair<ull, ui>> heap;

ui getParent(ui x){
	return (x-1) / 2;
}

ui getLeft(ui x){
	return 2*x + 1;	
}

ui getRight(ui x){
	return 2*x + 2;
}

void push(pair<ull, ui> node){
	ui i = heap.size();
	heap.push_back(node);
	
	while(i > 0 && heap[getParent(i)].first > heap[i].first){
		pair<ull, ui> tmp = heap[getParent(i)];
		heap[getParent(i)] = heap[i];
		heap[i] = tmp;
		i = getParent(i);
	}
}

void pop(){
	heap[0] = heap.back();
	heap.pop_back();
	
	ui i = 0;
	bool swapped = true;
	while(swapped){
		ui maxIndex = i;
		if(getLeft(i) < heap.size() && heap[getLeft(i)].first < heap[maxIndex].first){
			maxIndex = getLeft(i);
		}
		if(getRight(i) < heap.size() && heap[getRight(i)].first < heap[maxIndex].first){
			maxIndex = getRight(i);
		}
		
		swapped = maxIndex != i;
		pair<ull, ui> tmp = heap[maxIndex];
		heap[maxIndex] = heap[i];
		heap[i] = tmp;
		i = maxIndex;
	}
}

vector<pair<ull, ui>> cost[100001];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
		
	while(m--){
		ui tmp1, tmp2;
		ull tmp3;
		cin >> tmp1 >> tmp2 >> tmp3;
		cost[tmp1].push_back({tmp3, tmp2});
		cost[tmp2].push_back({tmp3, tmp1});
	}
	
	bool visited[n+1];
	ull dist[n+1], ans = 0;
	int pred[n+1];
	
	for(ui x=0;x<=n;x++){
		visited[x] = false;
		pred[x] = -1;
		dist[x] = inf_ll;
	}
	
	push({0, 1});
	dist[1] = 0;
	while(!heap.empty()){
		pair<ull, ui> currentNode = heap.front();
		pop();
		
		if(!visited[currentNode.second]){
			visited[currentNode.second] = true;
			ans += dist[currentNode.second];
			
			for(ui x=0;x<cost[currentNode.second].size();x++){					
				ui targetNode = cost[currentNode.second][x].second;
				if(!visited[targetNode] && dist[targetNode] > cost[currentNode.second][x].first){
					dist[targetNode] = cost[currentNode.second][x].first;
					pred[targetNode] = currentNode.second;
					push({dist[targetNode], targetNode});
				}
			}
		}
	}

	cout << ans << "\n";
    return 0;
}

