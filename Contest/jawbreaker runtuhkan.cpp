#include <iostream>

using namespace std;

const int maxN = 26;
int data[maxN][maxN];
bool visited[maxN][maxN];

void down(int n, int m){
	for(int x=n-2;x>=0;x--){
		for(int y=0;y<m;y++){
			if(data[x][y] >= 0){
				int lastX = x;
				for(int a=x+1;a<n;a++){
					if(data[a][y] >= 0){
						break;
					}
					lastX = a;
				}
				if(lastX != x){
					data[lastX][y] = data[x][y];
					data[x][y] = -1;
				}
			}
		}
	}
}

void destroy(int n, int m, int b, int k, int value){
	if(data[b][k] == value){
		data[b][k] = -1;
		if(b > 0) destroy(n, m, b-1, k, value);
		if(b < n-1) destroy(n, m, b+1, k, value);
		if(k > 0) destroy(n, m, b, k-1, value);
		if(k < m-1) destroy(n, m, b, k+1, value);
	}
}

int takeAt(int n, int m, int b, int k, int value){
	if(visited[b][k]) return 0;
	int answer = 0;
	if(data[b][k] == value){
		visited[b][k] = true;
		answer++;
		if(b > 0) answer += takeAt(n, m, b-1, k, value);
		if(b < n-1) answer += takeAt(n, m, b+1, k, value);
		if(k > 0) answer += takeAt(n, m, b, k-1, value);
		if(k < m-1) answer += takeAt(n, m, b, k+1, value);
	}
	return answer;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin >> n >> m;
    
    for(int x=0;x<n;x++){
    	for(int y=0;y<m;y++){
    		cin >> data[x][y];
    	}
	}
	
	int maxValue = -1, lastValue, lastB, lastK;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(visited[x][y]) continue;
			int value = takeAt(n,m,x,y,data[x][y]);
			if(value > maxValue) {
				maxValue = value;
				lastValue = data[x][y];
				lastB = x;
				lastK = y;
			}
		}
	}
	
	destroy(n,m,lastB,lastK,lastValue);
	down(n,m);
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			int value = data[x][y];
			if(value < 0){
				cout << ".";
			} else {
				cout << value;
			}
			if(y != m-1) cout << " ";
		}
		cout << "\n";
	}
    return 0;
}
