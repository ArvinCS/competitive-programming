#include <iostream>

using namespace std;

const int maxN = 25;
int data[maxN][maxN];
bool visited[maxN][maxN];
int takeAt(int n, int m, int b, int k, int value){
	if(visited[b][k]) return 0;
	int answer = 0;
	visited[b][k] = true;
	if(data[b][k] == value){
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
	
	int b,k;
	cin >> b >> k;
	
	int answer = takeAt(n,m,b,k,data[b][k]);
	answer *= (answer -1);
	cout << answer << "\n";
    return 0;
}
