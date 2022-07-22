#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	pair<ll, ll> c[n];
	ll p[n];
	for(int x=0;x<n;x++){
		cin >> c[x].first >> c[x].second >> p[x];
	}	
	
	ll ans = 0;
	ll left = 0, right = 4e9;
	while(left <= right){
		ll mid = (left+right) >> 1;
		
		bool possible = false;
		for(int x=0;x<n;x++){
			bool visited[n];
			fill(visited, visited+n, false);
			
			queue<int> q;
			q.push(x);
			visited[x] = true;
			
			int cnt = 0;
			while(!q.empty()){
				int curNode = q.front();
				q.pop();
				
				cnt++;
				for(int y=0;y<n;y++){
					if(!visited[y] && abs(c[y].first-c[curNode].first)+abs(c[y].second-c[curNode].second) <= p[curNode]*mid){
						visited[y] = true;
						q.push(y);
					}
				}
			}
			
			if(cnt == n){
				possible = true;
				break;
			}
		}
		
		if(possible){
			ans = mid;
			right = mid-1;
		} else {
			left = mid+1;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

