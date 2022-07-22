#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

vector<int> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int s;
	cin >> s;
	
	s--;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
	}
	
	int id[n];
	fill(id, id+n, -1);
	
	int track[n];
	fill(track, track+n, -1);
	
	vector<int> ans1, ans2;
	bool found = false;
	for(auto idx : adj[s]){
		if(id[idx] != -1){
			found = true;
			ans1.push_back(idx);
			ans1.push_back(s);
			
			int node = idx;
			while(node != s){
				ans2.push_back(node);
				node = track[node];
			}
			ans2.push_back(s);
			break;
		}
		
		queue<int> q;
		track[idx] = s;
		id[idx] = idx;
		q.push(idx);
		
		while(!q.empty()){
			int curNode = q.front();
			q.pop();
			
			for(auto nxt : adj[curNode]){
				if(nxt == s) continue;
				if(track[nxt] == -1){
					track[nxt] = curNode;
					id[nxt] = idx;
					q.push(nxt);
				} else {
					if(id[nxt] != idx){
						found = true;
						
						ans1.push_back(nxt);
						int node = curNode;
						while(node != s){
							ans1.push_back(node);
							node = track[node];
						}
						ans1.push_back(s);
						
						node = nxt;
						while(node != s){
							ans2.push_back(node);
							node = track[node];
						}
						ans2.push_back(s);
						break;
					}
				}
			}
			if(found) break;
		}
		if(found) break;
	}
	
	if(found){
		cout << "Possible\n";
		
		reverse(ans1.begin(), ans1.end());
		reverse(ans2.begin(), ans2.end());
		
		cout << ans1.size() << "\n";
		for(int x=0;x<ans1.size();x++){
			if(x > 0) cout << " ";
			cout << ans1[x]+1;
		}
		cout << "\n";
		
		cout << ans2.size() << "\n";
		for(int x=0;x<ans2.size();x++){
			if(x > 0) cout << " ";
			cout << ans2[x]+1;
		}
		cout << "\n";
	} else {
		cout << "Impossible\n";
	}
    return 0;
}

