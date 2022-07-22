#include "Anna.h"
#include <bits/stdc++.h>
	
using namespace std;
	
#define ll long long
	
namespace {
	
int variable_example = 0;
	const int maxN = 1e5 + 5;	
}
	
void Anna(int N, std::vector<char> S) {
	// 1 as store this first X or any Z after first Xa
	// 0 otherwise
	
	vector<int> v;
	ll pos = -1;
	bool fX = false;
	for(int x=0;x<N;x++){
		if(S[x] == 'Z'){
			if(fX && (x+1 == N || S[x+1] != 'Z')){
				v.push_back(1);
			} else {
				v.push_back(0);
			}
			// Send(fX);
		} else if(S[x] == 'Y'){
			// Send(0);
			v.push_back(0);
		} else if(S[x] == 'X'){
			if(!fX){
				v.push_back(1);
				// Send(1);
				fX = true;
				pos = x;
			} else {
				v.push_back(0);
				// Send(0);
			}
		}
	}
	
	// guaranteed bit 1 at most N/2 + 1
	// alternating, only special case where first X and any Z are adjacent.

	// first 16 bits are location of first X
	// if not exist: ok delete all
	// else :
	// check first bit after loc
	// if 0 length is odd
	// - if one:
	// - - 
	// - else:
	
	pos++;
	for(int y=0;y<17;y++){
		if(pos&(1ll << y)){
			Send(1);
		} else {
			Send(0);
		}
	}
	
	if(pos == 0){
		return;
	}
	
	ll cnt[90];
	ll sum = 2;
    ll table[90];
    table[0] = 1; cnt[0] = 1;
    table[1] = 1; cnt[1] = 2;
    for(int x=2;x<88;x++){
    	table[x] = 0;
		for(int y=0;y<=x-2;y++){
    		table[x] += table[y];
		}
		
		sum += table[x];
		cnt[x] = sum;
	}
	
//	cout << "... " << pos << "\n";
	while(pos < v.size()){
		ll val = 0;
		for(int x=85;x>=0;x--){
			if(pos+x < v.size() && v[pos+x] == 1){
//				cout << "+ " << x << " " << val << "+" << cnt[x] << "\n";
				val += cnt[x];
			}
		}
		
		for(int y=0;y<60;y++){
			if(val&(1ll << y)){
				Send(1);
			} else {
				Send(0);
			}
		}
		pos += 86;
	}
	// Send(v[0]);
	// bool skip = false;
	// for(int x=0;x<N;x++){
	// 	if(skip){
	// 		skip = false;
	// 		continue;
	// 	}
	
	// 	if(v[x] == 0){
	// 		if(x+1 == N || v[x+1] == 1){
	// 			Send(0);
	// 			if(x+1 < N && v[x+1] == 1) Send(1);
	// 			else Send(0);
	// 		} else {
	// 			Send(1);
	// 			if(x+2 < N && v[x+2] == 1){
	// 				Send(1);
	// 			} else {
	// 				Send(0);
	// 			}
	// 			skip = true;
	// 		}
	// 	}
	// }
}
