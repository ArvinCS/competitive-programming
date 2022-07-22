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

const short maxN = 1002;

bool visited[maxN][maxN];
char data[maxN][maxN];

vector<pair<short, pair<short, short>>> heap;

int getParent(int index){
	return (index - 1)/2;
}

int getLeft(int index){
	return 2*index + 1;
}

int getRight(int index){
	return 2*index + 2;
}

void push(pair<short, pair<short, short>> p){
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

	char tmp;
	for(short x=0;x<7;x++) cin >> tmp;

	short r, c, startX, startY;
	cin >> r >> c;
	
	int cnt = 0;
	for(short x=0;x<r;x++){
		for(short y=0;y<c;y++){
			cin >> data[x][y];
			visited[x][y] = false;
			
			if(data[x][y] == '.') cnt++;
			if(data[x][y] == 'S'){
				startX = x; startY = y;
			}
		}
	}	

	if(cnt == 0){
		cout << "0\n";
		return 0;
	}
	
	push({0, {startX,startY}});

	while(!heap.empty()){
		pair<short, pair<short, short>> p = heap.front();
		pop();
		
		short curX = p.second.first, curY = p.second.second;
		
		if(visited[curX][curY]) continue;
		visited[curX][curY] = true;
		
		short val = p.first;
		if(data[curX][curY] == 'T'){
			cout << val << "\n";
			return 0;
		}

		for(short x=curX+1;x<r;x++){
			if(data[x][curY] != '.'){
				if(visited[x][curY]) break;
				if(data[x-1][curY] == '.'){
					push({val+1, {x,curY}});
					break;
				} else {
					push({val, {x,curY}});
				}
			}
		}	
		for(short x=curX-1;x>=0;x--){
			if(data[x][curY] != '.'){
				if(visited[x][curY]) break;
				if(data[x+1][curY] == '.'){
					push({val+1, {x,curY}});
					break;
				} else {
					push({val, {x,curY}});
				}
			}
		}	

		for(short y=curY+1;y<c;y++){
			if(data[curX][y] != '.'){
				if(visited[curX][y]) break;
				if(data[curX][y-1] == '.'){
					push({val+1, {curX,y}});
					break;
				} else {
					push({val, {curX,y}});
				}
			}
		}
		
		for(short y=curY-1;y>=0;y--){
			if(data[curX][y] != '.'){
				if(visited[curX][y]) break;
				if(data[curX][y+1] == '.'){
					push({val+1, {curX,y}});
					break;
				} else {
					push({val, {curX,y}});
				}
			}
		}
	}

	cout << "-1\n";
    return 0;
}
