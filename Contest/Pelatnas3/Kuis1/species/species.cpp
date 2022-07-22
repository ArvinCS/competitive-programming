#include "species.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e6 + 5;
const int logN = log2(maxN)+1;

int l[maxN], r[maxN], cnt[maxN], extra = 0;
bool visited[maxN];
vector<int> v;

void init(std::string G, std::vector<int> P) {
	int N = G.size();
	
	fill(l, l+N, -1);
	fill(r, r+N, -1);
	fill(visited, visited+N, false);
	
	for(int x=1;x<N;x++){
		if(G[x] == 'A'){
			l[P[x]] = x;
		} else {
			r[P[x]] = x;
		}
	}
	
	if(r[0] != -1){
		queue<pair<int, bool>> q;
		q.push({0, false});
		
		while(!q.empty()){
			int curNode = q.front().first;
			bool hasB = q.front().second;
			q.pop();
			
			visited[curNode] = hasB;
			if(!hasB) extra++;
			v.push_back(curNode);
			if(l[curNode] != -1){
				q.push({l[curNode], hasB});
			}
			if(r[curNode] != -1){
				q.push({r[curNode], hasB|1});
			}
		}
	}
	
	fill(cnt, cnt+N, -1);
	
	for(int x=0;x<v.size();x++){
		cnt[v[x]] = x+1;
	}
}

int count_species(int S, int T) {
	if(cnt[S] > cnt[T]) swap(S, T);
	
//	cout << cnt[S] << " " << cnt[T] << " - " << ok[S] << " " << ok[T] << "\n";
	if(!visited[S] && !visited[T]){
		return extra;
	} else if(!visited[S]){
		return cnt[T] + extra;
	} else {
		return cnt[T] - cnt[S] + 1;
	}
}
