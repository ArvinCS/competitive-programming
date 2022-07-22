#include "Bruno.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

namespace {

int variable_example = 0;

int FunctionExample(int P) { return 1 - P; }

}  // namespace

void Bruno(int N, int L, std::vector<int> A) {
	ll pos = 0;
	for(int y=0;y<17;y++){
		if(A[y] == 1){
			pos += (1ll << y);
		}
	}
	
	if(pos == 0){
		for(int y=0;y<N;y++){
			Remove(y);
		}
		return;
	}
	
//	for(auto val : A){
//		cout << val << " ";
//	}cout << "\n";
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
	
	vector<int> v(N, 0);
	v[pos-1] = 1;
	
	ll idx = 17;
	while(idx < L){
		ll state = 0;
		for(int y=0;y<60;y++){
			if(A[idx++] == 1){
				state += (1ll << y);
			}
		}
		
//		cout << "= " << state << "\n";
//		ll val = 0;
		for(int y=85;y>=0;y--){
			if(cnt[y] <= state){
//				cout << y << " " << state << "-" << cnt[y] << "\n";
				state -= cnt[y];
				if(pos+y < N) v[pos+y] = 1;
//				val += (1ll << y);
			}	
		}
		
//		for(int y=0;y<86;y++){
//			if(pos+y >= N) break;
//			v[pos+y] = ((val&(1ll << y)) != 0);
//		}
		pos += 86;
	}
//	 for(auto val : v){
//	 	cout << val << " ";
//	 }cout << "\n";
//	 cout << v.size() << "\n";
	vector<int> ans;
	pos = -1;
	int lst = 0;
	for(int x=0;x<v.size();x++){
		if(v[x] == 1){
			if(pos == -1){
				pos = x;
				lst = x+1;
			} else {
				for(int y=x-1;y>=lst;y--){
					ans.push_back(y);
				}
				ans.push_back(x);
				lst = x+1;
			}
		}
	}
	
	for(int x=0;x<=pos;x++){
		ans.push_back(x);
	}
	for(int x=lst;x<N;x++){
		ans.push_back(x);
	}

	for(auto val : ans){
		// cout << "- " << val << "\n";
		Remove(val);
	}
}
