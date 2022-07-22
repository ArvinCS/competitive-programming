#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

const short maxN = 1001;

us n, m, startX, startY, endX, endY;
int data[maxN][maxN], table[maxN][maxN];
vector<pair<int, pair<us, us>>> heap;

int getParent(int index){
	return (index - 1)/2;
}

int getLeft(int index){
	return 2*index + 1;
}

int getRight(int index){
	return 2*index + 2;
}

void push(pair<int, pair<us, us>> p){
	int index = heap.size();
	heap.push_back(p);
	
	while(index > 0 && heap[getParent(index)].first > heap[index].first){
		swap(heap[getParent(index)], heap[index]);
		index = getParent(index);
	}
}

void pop(){
	heap[0] = heap.back();
	heap.pop_back();
	
	int index = 0;
	bool swapped = true;
	while(swapped){
		int bestIndex = index;
		if(getLeft(index) < heap.size() && heap[getLeft(index)].first < heap[bestIndex].first){
			bestIndex = getLeft(index);
		}
		if(getRight(index) < heap.size() && heap[getRight(index)].first < heap[bestIndex].first){
			bestIndex = getRight(index);
		}
		
		swapped = (bestIndex != index);
		swap(heap[bestIndex], heap[index]);
		index = bestIndex;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> m;
	
	for(us x=1;x<=n;x++){
		for(us y=1;y<=m;y++){
			cin >> data[x][y];
			table[x][y] = inf_int;
		}
	}
	
	cin >> startX >> startY >> endX >> endY;
	
	int best = inf_int;
	push({0, {startX, startY}});
	while(!heap.empty()){
		pair<us, us> node = heap.front().second;
		int cost = heap.front().first;
		pop();
		
		table[node.first][node.second] = cost;
		if(node.first == endX && node.second == endY){
			best = min(cost, best);
			break;
		}
		
		if(node.first < n && table[node.first+1][node.second] > cost){
			push({max(cost, data[node.first+1][node.second]), {node.first+1, node.second}});
		}
		if(node.second < m && table[node.first][node.second+1] > cost){
			push({max(cost, data[node.first][node.second+1]), {node.first, node.second+1}});
		}
		if(node.first > 1 && table[node.first-1][node.second] > cost){
			push({max(cost, data[node.first-1][node.second]), {node.first-1, node.second}});
		}
		if(node.second > 1 && table[node.first][node.second-1] > cost){
			push({max(cost, data[node.first][node.second-1]), {node.first, node.second-1}});
		}
	}
	
	cout << best << "\n";
	
    return 0;
}

