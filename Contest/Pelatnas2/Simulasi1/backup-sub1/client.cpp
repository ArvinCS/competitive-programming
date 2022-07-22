#include "client.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 25;

vector<pair<int, int>> adjS[maxN];
int parentS[maxN];

void dfsS(int curNode, int prvNode){
	parentS[curNode] = prvNode;
	
	assert(curNode == 0 || (curNode > 0 && prvNode != -1));
	
	for(auto nxt : adjS[curNode]){
		if(nxt.first != prvNode){
			dfsS(nxt.first, curNode);
		}
	}
}

int client(int N, std::vector<int> A, std::vector<int> B, int W) {
	for(int x=0;x<N;x++){
		adjS[x].clear();
	}
	for(int x=0;x<N-1;x++){
		adjS[A[x]].push_back({B[x], x});
		adjS[B[x]].push_back({A[x], x});
	}
	
	dfsS(0, -1);
	
	int ans = 0;
	while(W != 0){
		ans += get_bit(W);
		W = parentS[W];
	}
	return ans;
}
