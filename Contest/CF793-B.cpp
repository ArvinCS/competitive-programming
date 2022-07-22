#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int p[n];
		for(int x=0;x<n;x++){
			cin >> p[x];
		}
		
		int lg = log2(n-1);
		int ans = (1 << (lg+1))-1;
		
		bool visited[n];
		fill(visited, visited+n, false);
		
		for(int x=0;x<n;x++){
			if(!visited[x]){
				if(p[x] == x){
					visited[x] = true;
					continue;
				}
				
				int mn = (1 << (lg+1))-1;
				
				queue<int> q;
				q.push(x);
				visited[x] = true;
				
				while(!q.empty()){
					int cur = q.front();
					q.pop();
					
					mn &= cur;
					if(!visited[p[cur]]){
						visited[p[cur]] = true;
						q.push(p[cur]);
					}
				}
				
				ans &= mn;
			}	
		}
		cout << ans << "\n";
	}
	
    return 0;
}

