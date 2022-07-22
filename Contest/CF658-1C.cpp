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
		int n, m, p;
		cin >> n >> m >> p;
		
		int b[n];
		for(int x=0;x<n;x++){
			cin >> b[x];
			b[x]--;
		}
		
		vector<int> c[n+1];
		
		for(int x=0;x<n;x++){
			c[b[x]].push_back(x);
		}
		
		int lst = 0;
		for(int x=0;x<=n;x++){
			if(c[x].empty()){
				lst = x;
				break;
			}
		}
		
		int ans[n];
		fill(ans, ans+n, -1);
		
		int rem = p-m;
		
		priority_queue<pair<int, int>> pq;
		for(int x=0;x<=n;x++){
			if(!c[x].empty()) pq.push({c[x].size(), x});
		}
		
		while(rem > 0 && pq.size() > 1){
			pair<int, int> p1 = pq.top();
			pq.pop();
			pair<int, int> p2 = pq.top();
			pq.pop();
			
			if(rem >= 2){
				if(rem % 2 == 0 || pq.empty()){
					rem -= 2;
					ans[c[p1.second].back()] = p2.second;
					ans[c[p2.second].back()] = p1.second;
					c[p1.second].pop_back();
					c[p2.second].pop_back();
				} else {
					pair<int, int> p3 = pq.top();
					pq.pop();
					
					rem -= 3;
					ans[c[p1.second].back()] = p3.second;
					ans[c[p2.second].back()] = p1.second;
					ans[c[p3.second].back()] = p2.second;
					c[p1.second].pop_back();
					c[p2.second].pop_back();
					c[p3.second].pop_back();
					
					if(c[p3.second].size() > 0) pq.push({c[p3.second].size(), p3.second});
				}
			} else {
				rem--;
				ans[c[p1.second].back()] = p2.second;
				ans[c[p2.second].back()] = lst;
				c[p1.second].pop_back();
				c[p2.second].pop_back();
			}
			
			if(c[p1.second].size() > 0) pq.push({c[p1.second].size(), p1.second});
			if(c[p2.second].size() > 0) pq.push({c[p2.second].size(), p2.second});
		}
		
		for(int x=0;x<n;x++){
			if(ans[x] == -1){
				if(m > 0){
					ans[x] = b[x];
					m--;
				} else {
					ans[x] = lst;
				}
			}
		}
		
		if(rem > 0 || m > 0){
			cout << "NO\n";
			continue;
		}
		
		cout << "YES\n";
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[x]+1;
		}
		cout << "\n";
	}
	
    return 0;
}


