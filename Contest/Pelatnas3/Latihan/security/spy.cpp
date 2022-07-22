#include "spy.h"
#include <bits/stdc++.h>

using namespace std;

const int sz = 5128;

std::vector<int> spy(std::vector<int> A, std::vector<int> B, std::vector<int> C) {
    int N = A.size();
    int M = B.size();

    vector<int> ans;
    for(int x=0;x<18;x++){
        if(C.size()&(1 << x)){
            ans.push_back(1);
        } else {
            ans.push_back(0);
        }
    }

    vector<int> v, w;
    int pos = 0;
    for(int x=0;x<N;x++){
        if(pos < C.size() && A[x] == C[pos]){
            v.push_back(x);
            pos++;
        }
    }
    pos = 0;
    for(int x=0;x<M;x++){
        if(pos < C.size() && B[x] == C[pos]){
            w.push_back(x);
            pos++;
        }
    }
    
    assert(w.size() == v.size());
    assert(w.size() == C.size());
    
    pos = 0;
    int cur = 0, l = -1;
    while(cur < N){
        int r = l;
        while(pos < C.size()){
            if(cur <= v[pos] && v[pos] < cur+sz){
                r = w[pos];
                pos++;
            } else {
                break;
            }
        }
		
		if(pos == C.size()){
			r = M-1;
		}
		
        for(int x=0;x<18;x++){
            if((r-l)&(1 << x)){
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }
        }
        
//        cout << cur << "," << cur+sz-1 << " " << l+1 << " " << r << "\n";
		assert(l <= r);
        l = r;
        cur += sz;
    }
	assert(l == M-1);
	assert(ans.size() <= 1e6);
    return ans;
}
