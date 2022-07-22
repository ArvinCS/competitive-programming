#include "jumps.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;
const int logN = log2(maxN)+1;

int l[maxN], r[maxN];
bitset<maxN> j[logN][maxN];
int n;
vector<int> h;

void init(int N, vector<int> H) {
	n = N;
	h = H;
	h.push_back(1e9);
	
	stack<int> st;
	for(int x=0;x<n;x++){
		while(!st.empty() && h[st.top()] < h[x]) st.pop();
		if(!st.empty()){
			l[x] = st.top();
		} else {
			l[x] = n;
		}
		st.push(x);
	}
	while(!st.empty()) st.pop();
	for(int x=n-1;x>=0;x--){
		while(!st.empty() && h[st.top()] < h[x]) st.pop();
		if(!st.empty()){
			r[x] = st.top();
		} else {
			r[x] = n;
		}
		st.push(x);
	}
	
	int pos[n];
	for(int x=0;x<n;x++){
		pos[h[x]-1] = x;
	}
	for(int x=n-1;x>=0;x--){
		if(l[x] != n){
			j[0][x] |= l[x];
			
			for(int i=1;i<logN;i++){
				int cnt = (1 << i)-1;
				for(int k=logN-1;k>=0;k--){
					if(cnt >= (1 << k)){
						j[i][x] |= j[k][l[x]];
						cnt -= (1 << k);
					}
				}
			}
		}
		if(r[x] != n){
			j[0][x] |= r[x];
			
			for(int i=1;i<logN;i++){
				int cnt = (1 << i)-1;
				for(int k=logN-1;k>=0;k--){
					if(cnt >= (1 << k)){
						j[i][x] |= j[k][r[x]];
						cnt -= (1 << k);
					}
				}
			}
		}
	}
}

int minimum_jumps(int a, int b, int c, int d) {
	if(a <= c && c <= b || a <= d && d <= b){
		return 0;
	}
	
	int ans = 1e9;
	
	int cnt = 1;
	for(int i=logN-1;i>=0;i--){
		if(!j[i][h[a]][h[c]]){
			cnt += (1 << i);
		}
	}
	
	for(int i=logN-1;i>=0;i--){
		if(!j[i][h[a]][h[c]]){
			cnt += (1 << i);
		}
	}
	if(h[c] <= j[0][node].first && j[0][node].first <= h[d]){
		ans = cnt;
	}
	
	if(ans == 1e9) ans = -1;
	return ans;
}
