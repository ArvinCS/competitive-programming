#include "game.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> ans;

void solve(int i, int state, int val, int lst, int lstinv){
	if(i < 0){
		ans.push_back(val);
		return;
	}
	
	int bit = (1 << i);
	int res1 = lst;
	int res1inv = lstinv;
	
	// if i-th bit is not set
	int res2 = (lst != -1 && (lst&bit) ? (lst^bit) : lstinv);
	if(!(res2&bit)){
		int newres2 = (lst != -1 && (lst&bit) ? (lst^bit) : ask_minimum_xor(state^bit));
		int res2inv = (lst != -1 && ((lst&bit) || !(lstinv&bit)) ? lstinv : ask_minimum_xor((state^bit)^(bit-1)));
//		if(!(lst != -1 && (lst&bit))) cout << i << " " << state << " " << val << " " << lst << " " << lstinv << " : " << " asked " << (state^bit) << " " << ((state^bit)^(bit-1)) << " " << newres2 << " " << res2inv << "\n";
		solve(i-1, state^bit, val, newres2, res2inv);
		
		if(!(res1&bit) && !(lstinv&bit)){
			res1inv = ask_minimum_xor(state^(bit-1));
//			cout << i << " " << state << " " << val << " " << lst << " " << lstinv << " " << (state^(bit-1)) << " created new\n";
		}
	}
	
	// if i-th bit is set
//	int res1 = lst;
	if(!(res1&bit)){
//		int res1inv = lstinv;
		solve(i-1, state, val|bit, res1, res1inv);
	}
}

std::vector<int> play_game(int N) {
	int bit = 30;
	int maxbit = (1 << bit);
	
	int res = ask_minimum_xor(maxbit-1);
	int resinv = ask_minimum_xor(0);
	
	solve(bit-1, maxbit-1, 0, res, resinv);
//	for(auto val : ans) cout << val << "\n";
	assert(ans.size() == N);
	return ans;
}
