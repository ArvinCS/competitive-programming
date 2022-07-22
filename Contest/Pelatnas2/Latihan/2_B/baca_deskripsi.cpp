#include "baca_deskripsi.h"
#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct Vertex {
	Vertex *parent;
	Vertex *child[2];
	int cnt;
	
	Vertex() : cnt(0), parent(nullptr) {
		for(int x=0;x<2;x++){
			child[x] = nullptr;
		}
	}
	
	Vertex(Vertex *parent) : cnt(0), parent(parent) {
		for(int x=0;x<2;x++){
			child[x] = nullptr;
		}
	}
};

vector<int> getAnswers(int n, int m, vector<int> a, vector<int> b){
	vector<int> ans;
	
	Vertex *trie = new Vertex();
	for(int x=0;x<n;x++){
		Vertex *cur = trie;
		
		for(int i=29;i>=0;i--){
			int bit = (1 << i);
			
			int idx = (a[x]&bit) != 0;
			if(!cur->child[idx]){
				cur->child[idx] = new Vertex(cur);
			}
			cur = cur->child[idx];
		}
		
		while(cur){
			cur->cnt++;
			cur = cur->parent;
		}
	}
	
	for(int x=0;x<m;x++){
		Vertex *cur = trie;
		int val = 0;
		for(int i=29;i>=0;i--){
			int bit = (1 << i);
			
			int idx = (b[x]&bit) != 0;
			if(cur->child[idx^1] && cur->child[idx^1]->cnt > 0){
				val |= bit;
				cur = cur->child[idx^1];
			} else {
				if(!cur->child[idx]){
					cur->child[idx] = new Vertex(cur);
				}
				cur = cur->child[idx];
			}
		}
		ans.push_back(val);
	}
	return ans;
} 
