#include "client.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 505;

int nS;
vector<pair<int, int>> adjS[maxN];
int szS[maxN], parentS[maxN], rootS[maxN], lstS[maxN];

void dfsS(int curNode, int prvNode){
	szS[curNode] = 1;
	parentS[curNode] = prvNode;
	
	for(auto nxt : adjS[curNode]){
		if(nxt.first != prvNode){
			dfsS(nxt.first, curNode);
			szS[curNode] += szS[nxt.first];
		}
	}
}

void hldS(int curNode, int prvNode, int r){
	rootS[curNode] = r;
	lstS[r] = curNode;
	
	int mx = 0, idx = -1;
	for(auto nxt : adjS[curNode]){
		if(nxt.first != prvNode){
			if(szS[nxt.first] > mx){
				mx = szS[nxt.first];
				idx = nxt.first;
			}
		}
	}
	
	for(auto nxt : adjS[curNode]){
		if(nxt.first != prvNode){
			if(nxt.first == idx){
				hldS(nxt.first, curNode, r);
			} else {
				hldS(nxt.first, curNode, nxt.first);
			}
		}
	}
}

int client(int N, std::vector<int> A, std::vector<int> B, int W) {
	nS = N;
	for(int x=0;x<N-1;x++){
		adjS[A[x]].push_back({B[x], x});
		adjS[B[x]].push_back({A[x], x});
	}
	
	dfsS(0, 0);
	hldS(0, -1, 0);
	
	int ans = 0;
	while(W != 0){
		if(rootS[W] != W){
			ans += get_bit(nS+W);
			W = rootS[W];
		} else {
			ans += get_bit(W);
			W = parentS[W];
		}
	}
	return ans;
}
