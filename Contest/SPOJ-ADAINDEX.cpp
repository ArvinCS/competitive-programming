#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
struct Vertex {
	Vertex *parent;
	Vertex *child[26];
	int cnt = 0, mx = 0;
	string s;
	
	Vertex(Vertex *parent) : parent(parent), cnt(0), mx(0) {
		for(int x=0;x<26;x++) child[x] = nullptr;
	}
	
	Vertex() : parent(nullptr), cnt(0), mx(0) {
		for(int x=0;x<26;x++) child[x] = nullptr;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	Vertex *trie = new Vertex();
	
	for(int x=0;x<n;x++){
		string s;
		cin >> s;
		
		Vertex *cur = trie;
		for(int y=0;y<s.length();y++){
			int idx = s[y] - 'a';
			
			if(!cur->child[idx]){
				cur->child[idx] = new Vertex(cur);
			}
			
			cur = cur->child[idx];
		}
		
		while(cur != NULL){
			cur->cnt++;
			cur = cur->parent;
		}
	}
	
	for(int x=0;x<q;x++){
		string s;
		cin >> s;
		
		Vertex *cur = trie;
		for(int y=0;y<s.length();y++){
			int idx = s[y] - 'a';
			
			if(!cur->child[idx]){
				cur->child[idx] = new Vertex(cur);
			}
			
			cur = cur->child[idx];
		}
		
		cout << cur->cnt << "\n";
	}
    return 0;
}
