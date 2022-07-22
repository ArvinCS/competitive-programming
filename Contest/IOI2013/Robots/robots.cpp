#include <bits/stdc++.h>
#include "robots.h"

using namespace std;

int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[]) {
	pair<int, int> p[T];
	for(int x=0;x<T;x++){
		p[x].first = W[x];
		p[x].second = S[x];
	}
	
	sort(p, p+T);
	sort(X, X+A);
	sort(Y, Y+B);
	
	int left = 1, right = T, ans = T+1;
	while(left <= right){
		int mid = (left+right) >> 1;
		
		priority_queue<int> pq;		
		int pos = 0;
		for(int x=0;x<A;x++){
			while(pos < T && p[pos].first < X[x]){
				pq.push(p[pos].second);
				pos++;
			}
			
			int cnt = mid;
			while(!pq.empty() && cnt > 0){
				pq.pop();
				cnt--;
			}
		}
		
		while(pos < T){
			pq.push(p[pos].second);
			pos++;
		}
		
		for(int x=B-1;x>=0;x--){
			int cnt = mid;
			while(!pq.empty() && pq.top() < Y[x] && cnt > 0){
				pq.pop();
				cnt--;
			}
		}
		
		if(pq.empty()){
			ans = min(ans, mid);
			right = mid-1;	
		} else {
			left = mid+1;
		}
	}
	
    return (ans <= T ? ans : -1);
}
