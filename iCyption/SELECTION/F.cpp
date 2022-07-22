#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, s;
	cin >> n >> m >> s;
	
	bool visited[n];
	fill(visited, visited+n, false);
	visited[s-1] = true;
	
	int a,b;
	for(int x=0;x<m;x++){
		cin >> a >> b;
		if(visited[a-1]){
			visited[b-1] = true;
		} else if(visited[b-1]){
			visited[a-1] = true;
		}
	}
	
	bool newline = false;
	for(int x=0;x<n;x++){
		if(visited[x]){
			if(newline) cout << " ";
			cout << x + 1;
			newline = true;
		}
	}
	
	cout << "\n";
    return 0;
}
