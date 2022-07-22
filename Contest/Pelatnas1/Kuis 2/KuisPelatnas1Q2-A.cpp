#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 6e5 + 5; // multiplied by 2
const int logN = log2(maxN);

struct DSU {
	int parrent[maxN][logN+1], level[maxN];
	
	void reset(){
		for(int x=0;x<maxN;x++){
			level[x] = 0;
			for(int y=0;y<=logN;y++){
				parrent[x][y] = x;
			}
		}
	}
	
	int getParrent(int x){
		return parrent[x][0];
	}	
	
	void merge(int a, int b){
//		cout << a << " " << b << "\n";
		if(a == b) return;
		
		level[b] = level[a]+1;
		parrent[b][0] = a;
		
		for(int x=1;x<=logN;x++){
			parrent[b][x] = parrent[parrent[b][x-1]][x-1];
		}
	}
	
	int compute(int x, int y){
		if(level[x] > level[y]){
			swap(x, y);
		}
		
		int ans = 0;
		for(int i=logN;i>=0;i--){
			if(level[x] <= level[y]-(1 << i)){
				y = parrent[y][i];
			}
		}
		
		if(x == y) return level[x]-1;
		
		for(int i=logN;i>=0;i--){
			if(parrent[x][i] != parrent[y][i]){
				x = parrent[x][i];
				y = parrent[y][i];
			}
		}
		
		return level[x]-1;
	}
};

DSU dsu;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	dsu.reset();
	dsu.merge(0, n+1);
	
	for(int i=1;i<=n;i++){
		char t;
		cin >> t;
		
		if(t == 'a'){
			int v;
			cin >> v;
			
			dsu.merge(dsu.getParrent(n+1+v), i);
			dsu.merge(i, n+1+i);
		} else if(t == 'b'){
			int v;
			cin >> v;
			
			cout << dsu.getParrent(n+1+v) << "\n";
			dsu.merge(dsu.getParrent(dsu.getParrent(n+1+v)), n+1+i);
		} else if(t == 'c'){
			int v, w;
			cin >> v >> w;
			
			dsu.merge(dsu.getParrent(n+1+v), n+1+i);
			cout << dsu.compute(n+1+w, n+1+i) << "\n";
		} else {
			assert(false);
		}
	}
	
	return 0;
}
