#include <iostream>

using namespace std;

const int maxN = 26;
int data[maxN][maxN];
bool visited[maxN][maxN] = { false };

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
	if(data[b][k] == -1) return;
	if(data[b][k] == value){
		data[b][k] = -1;
		if(b > 0) destroy(n, m, b-1, k, value);
		if(b < n-1) destroy(n, m, b+1, k, value);
		if(k > 0) destroy(n, m, b, k-1, value);
		if(k < m-1) destroy(n, m, b, k+1, value);
	}
}

int takeAgainAt(int n, int m, int b, int k, int value, bool visited2[][maxN]){
	if(visited2[b][k] || data[b][k] == -1) return 0;
	int answer = 0;
	if(data[b][k] == value){
		visited2[b][k] = true;
		answer++;
		if(b > 0) answer += takeAgainAt(n, m, b-1, k, value, visited2);
		if(b < n-1) answer += takeAgainAt(n, m, b+1, k, value, visited2);
		if(k > 0) answer += takeAgainAt(n, m, b, k-1, value, visited2);
		if(k < m-1) answer += takeAgainAt(n, m, b, k+1, value, visited2);
	}
	return answer;
}

int takeAt(int n, int m, int b, int k, int value){
	if(visited[b][k] || data[b][k] == -1) return 0;
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
    
    int saveData[maxN][maxN];
    for(int x=0;x<n;x++){
    	for(int y=0;y<m;y++){
    		cin >> saveData[x][y];
    	}
	}
    
	int maxValue = 0;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(visited[x][y]) continue;
			copy(&saveData[0][0], &saveData[0][0]+maxN*maxN, &data[0][0]);
			int value = takeAt(n,m,x,y,data[x][y]);
			destroy(n,m,x,y,data[x][y]);
			down(n,m);
			if(value <= 1) continue;
			int maxValue2 = 0;
			for(int i=0;i<n;i++){
				for(int o=0;o<m;o++){
					if(data[i][o] == -1) continue;
					bool visited2[maxN][maxN] = { false };
					int value2 = takeAgainAt(n,m,i,o, data[i][o], visited2);
					if(value2 >= maxValue2){
						maxValue2 = value2;
					}
				}
			}
			int result = (value * (value-1)) + (maxValue2 * (maxValue2-1));
			if(result >= maxValue) {
				maxValue = result;
			}
		}
	}
    
    cout << maxValue << "\n";
	return 0;
}
