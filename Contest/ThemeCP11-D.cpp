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
		int n, m, k;
		cin >> n >> m >> k;
		
		// there will be n%m tables with capacity (n/m + 1)
		// how to distribute n%m * k to n people?
		// greedy from lowest val?
		
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		for(int x=0;x<n;x++){
			pq.push({0, x});
		}
		
		vector<vector<int>> ans[k];
		
		int extra = n%m;
		for(int i=0;i<k;i++){
			vector<pair<int, int>> v, w;
			for(int j=1;j<=extra;j++){
				vector<int> order;
				for(int x=1;x<=n/m+1;x++){
					assert(!pq.empty());
					pair<int, int> p = pq.top();
					pq.pop();
					
					v.push_back(p);
					order.push_back(p.second);
				}
				ans[i].push_back(order);
			}
			
			for(int j=1;j<=m-extra;j++){
				vector<int> order;
				for(int x=1;x<=n/m;x++){
					assert(!pq.empty());
					pair<int, int> p = pq.top();
					pq.pop();
					
					w.push_back(p);
					order.push_back(p.second);
				}
				ans[i].push_back(order);
			}
			
			while(!v.empty()){
				v.back().first++;
				pq.push(v.back());
				v.pop_back();
			}
			while(!w.empty()){
				pq.push(w.back());
				w.pop_back();
			}
		}
		
		for(int i=0;i<k;i++){
			for(auto v : ans[i]){
				cout << v.size();
				for(int x=0;x<v.size();x++){
					cout << " " << v[x]+1;
				}
				cout << "\n";
			}
		}
		cout << "\n";
	}
	
    return 0;
}

