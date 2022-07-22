#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxQ = 1e5 + 5;

struct Node {
	int cnt[26];
	pair<int, int> last = {-1, -1};
	Node *parent, *child[26];
	int color = -1, depth = 0;
	
	Node(int color = -1, int depth = 0) : color(color), depth(depth) {
		for(int x=0;x<26;x++){
			child[x] = nullptr;
			cnt[x] = 0;
		}
		
		last = {color, depth};
	}
	
	Node(Node *parent, int color = -1, int depth = 0) : parent(parent), color(color), depth(depth) {
		for(int x=0;x<26;x++){
			child[x] = nullptr;
			cnt[x] = 0;
		}
		
		last = {color, depth};
		if(parent != NULL){
			if(parent->last.first == color){
				last = parent->last;
			}
		}
	}
};

vector<int> adj[maxQ];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int q;
	cin >> q;
	
	Node *t[q+1];
	bool exist[q+1];
	fill(exist, exist+q+1, false);
	
	// root
	t[0] = new Node(nullptr, -1, 0);
	exist[0] = true;
	
	ll ans = 0;
	int v = 1;
	for(int i=0;i<q;i++){
		int type;
		cin >> type;
		
		assert(type >= 1 && type <= 2);
		if(type == 1){
			int node;
			char c;
			cin >> node >> c;
			
			node--;
			int idx = (c - 'a');
			
			if(t[node]->child[idx] == NULL){
				t[node]->child[idx] = new Node(t[node], idx, t[node]->depth+1);
				ans++;
			}
			
			adj[node].push_back(v);
			t[node]->cnt[idx]++;
			t[v] = t[node]->child[idx];
			exist[v] = true;
			v++;
		} else if(type == 2){
			int node;
			cin >> node;
			
			node--;
			queue<pair<Node*, int>> q;
			q.push({t[node], node});
			
			while(!q.empty()){
				pair<Node*, int> p = q.front();
				q.pop();
				
//				cout << p.first->color << "\n";
//				cout << p.second << " -> " << exist[p.second] << " " << p.first->parent->cnt[p.first->color] << "\n";
				if(!exist[p.second] || p.first->parent->cnt[p.first->color] == 1){
					p.first->parent->cnt[p.first->color]--;
					ans--;
					exist[p.second] = false;
				}
				
				for(auto nxt : adj[p.second]){
					if(exist[nxt]){
						exist[nxt] &= exist[p.second];
						q.push({t[nxt], nxt});
					}
				}
				
				exist[p.second] = false;
			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}
