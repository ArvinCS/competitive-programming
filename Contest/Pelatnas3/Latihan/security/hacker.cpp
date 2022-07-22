#include "spy.h"
#include <bits/stdc++.h>

using namespace std;

const int sz = 5128;
const int maxM = 2e5 + 5;

pair<int, vector<pair<int, int>>> dp[sz+5], new_dp[sz+5];

std::vector<int> hacker(std::vector<int> A, std::vector<int> B, std::vector<int> C) {
    int N = A.size();
    int M = B.size();
    int L = 0;
    for(int x=0;x<18;x++){
        if(C[x] == 1){
          L += (1 << x);
        }
    }
	
//	for(auto val : C){
//		cout << val << " ";
//	}cout << "???\n";
    int id[M];
    fill(id, id+M, -1);
    
    int pos = 18, cnt = 0;
    int cur = 0, l = -1;
    while(cur < N){
        int r = l;
        for(int x=0;x<18;x++){
//        	assert(pos < C.size());
            if(C[pos++]){
              r += (1 << x);
            }
        }

        for(int x=l+1;x<=r;x++){
            id[x] = cnt;
        }
		
		l = r;
        cnt++;
        cur += sz;
    }
	
	for(int x=0;x<M;x++){
		assert(id[x] >= 0);
	}
//	for(int x=0;x<M;x++){
//		cout << x+1 << "("<< id[x] << ") ";
//	}cout << " ---\n";
    vector<int> ans;
	    
    for(int x=0;x<sz+5;x++){
    	dp[x] = {0, {}};
	}
    for(int x=0;x<M;x++){ // O(M.SZ)
    	if(id[x] == -1) continue;
    	
    	int l = id[x]*sz, r = min(N, (id[x]+1)*sz);
    	
        for(int y=0;y<sz+5;y++){
        	new_dp[y] = {0, {}};
		}
        for(int y=l;y<r;y++){
            int idx = y-l;
            assert(idx >= 0 && idx < sz);
            if(A[y] == B[x]){
                if(idx > 0 && x > 0 && id[x-1] == id[x]) new_dp[idx] = {dp[idx-1][0]+1, idx, x};
                else new_dp[idx] = {1, idx, x};
            } else {
                if(x > 0 && id[x-1] == id[x]) new_dp[idx] = max(new_dp[idx], dp[idx]);
                if(idx > 0) new_dp[idx] = max(new_dp[idx], new_dp[idx-1]);
            }
            if(mx < new_dp[idx]) mx = new_dp[idx];
        }
		
		for(int y=0;y<sz+5;y++){
        	dp[y] = new_dp[y];
		}
        if(x+1 == M || id[x] != id[x+1]){
        	vector<int> tmp;
			int pos1 = mx[1], pos2 = mx[2];
			while(pos1 >= 0 && pos2 >= 0 && id[x] == id[pos2]){
//				cout << pos1 << " " << pos2 << "\n";
				pair<int, int> new_pos = {dp[pos1][pos2][1], dp[pos1][pos2][2]};
				pos1 = new_pos.first;
				pos2 = new_pos.second;
				
				if(pos1 < 0 || pos2 < 0 || id[pos2] != id[x]) break;
				
//				cout << pos1 << "-" << pos2 << " = " << B[pos2] << "\n";
				tmp.push_back(B[pos2]);
				pos1--;
				pos2--;
			}
			
			for(int x=tmp.size();x>=1;x--){
				ans.push_back(tmp[x-1]);
			}
//			cout << " _____ \n";
        }
    }
    
//    for(auto val : ans){
//    	cout << val << " ";
//	}cout << " ===\n";
//	assert(ans.size() >= L);
    return ans;
}
