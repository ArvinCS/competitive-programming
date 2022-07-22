#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int t[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> t[x][y];
		}
	}
	
	int prefix[n][m];
	for(int x=0;x<n;x++){
		int sum = 0;
		for(int y=0;y<m;y++){
			sum += t[x][y];
			prefix[x][y] = sum;
		}
	}
	
	int d;
	cin >> d;
	
	pair<int, int> p[d];
	for(int x=0;x<d;x++){
		cin >> p[x].first >> p[x].second;
		p[x].first--; p[x].second--;
	}
	
	int left[n][n][m], right[n][n][m];
	fill(*left[0], *left[n], 1e9);
	fill(*right[0], *right[n], 1e9);
	
	for(int x=0;x<n;x++){
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
		
		left[x][x][0] = t[x][0];
		pq.push(make_tuple(left[x][x][0], x, 0));
		
		while(!pq.empty()){
			tuple<int, int, int> tup = pq.top();
			pq.pop();
			
			int cost = get<0>(tup);
			int posX = get<1>(tup), posY = get<2>(tup);
			
			if(left[x][posX][posY] < cost) continue;
			
			if(posY == 0 || posY == m-1){
				if(posX > 0 && left[x][posX-1][posY] > left[x][posX][posY]+t[posX-1][posY]){
					left[x][posX-1][posY] = left[x][posX][posY]+t[posX-1][posY];
					pq.push(make_tuple(left[x][posX-1][posY], posX-1, posY));
				}
				if(posX < n-1 && left[x][posX+1][posY] > left[x][posX][posY]+t[posX+1][posY]){
					left[x][posX+1][posY] = left[x][posX][posY]+t[posX+1][posY];
					pq.push(make_tuple(left[x][posX+1][posY], posX+1, posY));
				}
			}
			if(posY < m-1 && left[x][posX][posY+1] > left[x][posX][posY]+t[posX][posY+1]){
				left[x][posX][posY+1] = left[x][posX][posY]+t[posX][posY+1];
				pq.push(make_tuple(left[x][posX][posY+1], posX, posY+1));
			}
			if(posY > 0 && left[x][posX][posY-1] > left[x][posX][posY]+t[posX][posY-1]){
				left[x][posX][posY-1] = left[x][posX][posY]+t[posX][posY-1];
				pq.push(make_tuple(left[x][posX][posY-1], posX, posY-1));
			}
		}
		
		right[x][x][m-1] = t[x][m-1];
		pq.push(make_tuple(right[x][x][m-1], x, m-1));
		
		while(!pq.empty()){
			tuple<int, int, int> tup = pq.top();
			pq.pop();
			
			int cost = get<0>(tup);
			int posX = get<1>(tup), posY = get<2>(tup);
			
			if(right[x][posX][posY] < cost) continue;
			
			if(posY == 0 || posY == m-1){
				if(posX > 0 && right[x][posX-1][posY] > right[x][posX][posY]+t[posX-1][posY]){
					right[x][posX-1][posY] = right[x][posX][posY]+t[posX-1][posY];
					pq.push(make_tuple(right[x][posX-1][posY], posX-1, posY));
				}
				if(posX < n-1 && right[x][posX+1][posY] > right[x][posX][posY]+t[posX+1][posY]){
					right[x][posX+1][posY] = right[x][posX][posY]+t[posX+1][posY];
					pq.push(make_tuple(right[x][posX+1][posY], posX+1, posY));
				}
			}
			if(posY < m-1 && right[x][posX][posY+1] > right[x][posX][posY]+t[posX][posY+1]){
				right[x][posX][posY+1] = right[x][posX][posY]+t[posX][posY+1];
				pq.push(make_tuple(right[x][posX][posY+1], posX, posY+1));
			}
			if(posY > 0 && right[x][posX][posY-1] > right[x][posX][posY]+t[posX][posY-1]){
				right[x][posX][posY-1] = right[x][posX][posY]+t[posX][posY-1];
				pq.push(make_tuple(right[x][posX][posY-1], posX, posY-1));
			}
		}
	}
	
	ll ans = 0;
	for(int x=0;x<d;x++){
		if(x == 0){
			ans += left[0][p[x].first][p[x].second];
		} else {
			if(p[x-1].first == p[x].first){
				if(p[x-1].second < p[x].second){
					ans += min(prefix[p[x].first][p[x].second] - prefix[p[x].first][p[x-1].second], (p[x-1].second > 0 ? prefix[p[x].first][p[x-1].second-1] - prefix[p[x].first][0] : 0) + left[p[x].first][p[x].first][p[x].second] - (p[x-1].second == 0 ? t[p[x].first][p[x-1].second] : 0));					
				} else {
					ans += min(prefix[p[x].first][p[x-1].second-1] - (p[x].second > 0 ? prefix[p[x].first][p[x].second - 1] : 0), (p[x-1].second < m-1 ? prefix[p[x-1].first][m-2] - prefix[p[x-1].first][p[x-1].second] : 0) + right[p[x].first][p[x].first][p[x].second] - (p[x-1].second == m-1 ? t[p[x].first][p[x-1].second] : 0));					
				}
			} else {
				ans += min((p[x-1].second > 0 ? prefix[p[x-1].first][p[x-1].second-1] - prefix[p[x-1].first][0] : 0) + left[p[x-1].first][p[x].first][p[x].second] - (p[x-1].second == 0 ? t[p[x-1].first][p[x-1].second] : 0), (p[x-1].second < m-1 ? prefix[p[x-1].first][m-2] - prefix[p[x-1].first][p[x-1].second] : 0) + right[p[x-1].first][p[x].first][p[x].second] - (p[x-1].second == m-1 ? t[p[x-1].first][p[x-1].second] : 0));
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

