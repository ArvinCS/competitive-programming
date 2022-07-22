#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	bool visited[n];
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		a[x]--;
		visited[x] = false;
	}
	
	queue<int> q;
	q.push(m-1);
	
	int cnt = 0;
	while(!q.empty()){
		int curNode = q.front();
		q.pop();
		
		if(visited[curNode]) continue;
		cnt++;
		visited[curNode] = true;
		
		q.push(a[curNode]);
	}
	
	cout << cnt << "\n";
    return 0;
}

