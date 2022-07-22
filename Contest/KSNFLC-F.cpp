#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxNM = 1e6 + 5;

struct DSU {
	int parrent[2*maxNM], sz[2*maxNM];
	
	void reset(){
		for(int x=0;x<2*maxNM;x++){
			parrent[x] = x;
			sz[x] = 1;
		}
	}
	
	int getParrent(int x){
		if(parrent[x] == x) return x;
		return parrent[x] = getParrent(parrent[x]);
	}
	
	void merge(int x, int y){
		int a = getParrent(x);
		int b = getParrent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			parrent[b] = a;
			sz[a] += sz[b];
		}
	}
};

DSU dsu, dsu2;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int a[n][m], b[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> a[x][y];
		}
	}
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> b[x][y];
		}
	}
	
	dsu.reset();
	dsu2.reset();
	
	for(int y=0;y<m;y++){
		for(int x=1;x<n;x++){
			dsu.merge(maxNM+a[0][y], maxNM+a[x][y]);		
		}
	}
	for(int x=0;x<n;x++){
		for(int y=1;y<m;y++){
			dsu2.merge(maxNM+a[x][0], maxNM+a[x][y]);
		}
	}
	
	bool valid = true;
	for(int y=0;y<m;y++){
		for(int x=0;x<n;x++){
			if(dsu.getParrent(maxNM+b[0][y]) != dsu.getParrent(maxNM+b[x][y]) || dsu2.getParrent(maxNM+b[x][0]) != dsu2.getParrent(maxNM+b[x][y])){
				valid = false;
				break;
			}
		}
	}
	
	if(valid){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}
