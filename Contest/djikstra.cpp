#include <iostream>
#include <vector>

#define maxInt 10000001

short n, from, to;
int l,t, distance[501];
bool visited[501];

int minDistance(){
	int min = maxInt, index;
	for(int x=1;x<=n;x++){
		if(!visited[x] && distance[x] <= min){
			min = distance[x];
			index = x;
		}
	}
	return index;
}

void search(vector<int> jalan[], vector<int> tol[]){
	bool visited[n+1];
	for(int x=1;x<=n;x++){
		distance[x] = 10000001;
		visited[x] = false;
	}
	
	distance[from] = 0;
	for(int x=1;x<=n;x++){
		
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> n >> l >> t >> from >> to;

	for(int x=0;x<l;x++){
		int tmp, tmp2;
		cin >> tmp >> tmp2;
		jalan[tmp].push_back(tmp2);
		jalan[tmp2].push_back(tmp);
	}

	for(int x=0;x<t;x++){
		int tmp, tmp2;
		cin >> tmp >> tmp2;
		tol[tmp].push_back(tmp2);
		tol[tmp2].push_back(tmp);
	}

	djikstra(jalan, tol);
	
    return 0;
}
