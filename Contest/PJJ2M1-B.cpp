#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct Vertex {
	Vertex *parent;
	Vertex *child[2];
	int cnt = 0;

	Vertex(Vertex *parent) : parent(parent), cnt(0) {
		for(int x=0;x<2;x++) child[x] = nullptr;
	}
	
	Vertex() : parent(nullptr), cnt(0) {
		for(int x=0;x<2;x++) child[x] = nullptr;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}	
	
	Vertex *trie = new Vertex();
	ll ans = 0;
	ll cur = 0;
	for(int x=0;x<=n;x++){
		if(x > 0) cur ^= a[x-1];
		
		Vertex *t = trie;
		for(int i=30;i>=0;i--){
			int bit = (1 << i);
			if(m&bit){
				if(cur&bit){
					if(!t->child[0]) t->child[0] = new Vertex(t);
					t = t->child[0];
				} else {
					if(!t->child[1]) t->child[1] = new Vertex(t);
					t = t->child[1];
				}
			} else {
				if(cur&bit){
					if(t->child[0]) ans += t->child[0]->cnt;
					
					if(!t->child[1]) t->child[1] = new Vertex(t);
					t = t->child[1];
				} else {		
					if(t->child[1]) ans += t->child[1]->cnt;
					
					if(!t->child[0]) t->child[0] = new Vertex(t);
					t = t->child[0];
				}
			}
		}
		ans += t->cnt;
		
		t = trie;
		
		for(int i=30;i>=0;i--){
			int idx = (cur >> i)&1;
			
			if(!t->child[idx]){
				t->child[idx] = new Vertex(t);
			}
			
			t = t->child[idx];
		}
		
		while(t){
			t->cnt++;
			t = t->parent;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

