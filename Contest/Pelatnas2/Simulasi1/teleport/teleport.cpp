#include "teleport.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 205;
const int logN = log2(maxN)+1;

int cur = 0, idx = 1;
int depth[maxN], parent[logN][maxN];
pair<int, int> prv[maxN];
vector<int> v[maxN];

void dfs(int curNode){
	int k = ask_count_teleporters();
	for(int x=0;x<k;x++){
		use_teleporter(x);
		
		int lst = ask_last_teleporter();
		if(ask_news_channel() == 0){
			depth[idx] = depth[curNode]+1;
			parent[idx] = {curNode, lst};
			change_news_channel(2);
			v[1].push_back(idx);
			idx++;
		}
		
		use_teleporter(lst);
	}
}

std::vector<int> explore(int N, int X) {
	std::vector<int> ans(N, 0);
	ans[0] = N;
	
	fill(prv, prv+maxN, -1);
	
	int tmp = ask_count_teleporters();
	change_news_channel(1);
	
	for(int x=0;x<tmp;x++){
		use_teleporter(x);
		parent[idx]
		v[1].push_back(idx);
		idx++;
	}
	
	use_teleporter(0);
	change_news_channel(1);
	int c = ask_news_channel();
	int d = ask_count_teleporters();
	int e = ask_last_teleporter();
	
	
	
	return ans;
}
