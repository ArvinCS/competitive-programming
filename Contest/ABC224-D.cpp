#include <bits/stdc++.h>

using namespace std;

#define ll long long

set<vector<int>> st;
vector<int> adj[10];
vector<int> v(9, -1);

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n = 9, m;
	cin >> m;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int x=0;x<8;x++){
		int pos;
		cin >> pos;
		
		v[pos-1] = x;
	}
	
	st.insert(v);
	
	int ans = -1;
	queue<pair<vector<int>, int>> q;
	q.push({v, 0});
	
	while(!q.empty()){
		vector<int> w = q.front().first;
		int val = q.front().second;
		
		q.pop();
		
		bool ok = true;
		for(int x=0;x<8;x++){
			if(w[x] != x){
				ok = false;
			}
		}
		
		if(ok){
			ans = val;
			break;
		}
		
		for(int x=0;x<9;x++){
			if(w[x] == -1){
				for(auto nxt : adj[x]){
					swap(w[x], w[nxt]);
					
					if(!st.count(w)){
						st.insert(w);
						q.push({w, val+1});
					}
					
					swap(w[x], w[nxt]);
				}
				break;
			}
		}
	}

	cout << ans << "\n";
    return 0;
}

