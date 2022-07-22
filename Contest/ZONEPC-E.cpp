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

const int maxN = 505;

int ver[maxN][maxN], hor[maxN][maxN];

struct Node {
	int down, cost, x, y;	
};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m-1;y++){
			cin >> hor[x][y];
		}
	}
	for(int x=0;x<n-1;x++){
		for(int y=0;y<m;y++){
			cin >> ver[x][y];
		}
	}
	
	bool visited[n][m];
	fill(visited[0], visited[n], false);
	
	priority_queue<tuple<int, bool, int, int>, vector<tuple<int, bool, int, int>>, greater<tuple<int, bool, int, int>>> pq;
	pq.push(make_tuple(0,0,0,0));
	
	while(!pq.empty()){
		int cur = get<0>(pq.top());
		bool z = get<1>(pq.top());
		int x = get<2>(pq.top());
		int y = get<3>(pq.top());
		pq.pop();
		
		if(visited[x][y]) continue;
		visited[x][y] = true;
		
		if(x == n-1 && y == m-1){
			cout << cur << "\n";
			break;
		}
		
		if(y > 0 && !visited[x][y-1]){
			pq.push(make_tuple(cur+hor[x][y-1]+z, 0, x, y-1));
		}
		if(y < m-1 && !visited[x][y+1]){
			pq.push(make_tuple(cur+hor[x][y]+z, 0, x, y+1));
		}
		if(x < n-1 && !visited[x+1][y]){
			pq.push(make_tuple(cur+ver[x][y]+z, 0, x+1, y));
		}
		if(x > 0 && !visited[x-1][y]){
			pq.push(make_tuple(cur+1, 1, x-1, y));
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

