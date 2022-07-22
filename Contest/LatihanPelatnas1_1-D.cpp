#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 3e5 + 5;

int w[maxN], l[maxN], r[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int sz = n+m;
	
	fill(w, w+maxN, 1);
	fill(l, l+maxN, 0);
	fill(r, r+maxN, 0);
	
	int h = log2(sz+1);
	for(int i=h;i>=0;i--){
		int bit = (1 << i);
		int right = (1 << (i+1))-1;
		
		if(m >= bit && right <= sz){
			for(int y=bit;y<=right;y++){
				if(m > 0){
					w[y] = 2;
					m--;
				}
			}
		}
	}
	
	if(m > 0){
		cout << "-1\n";
		return 0;
	}
	
	for(int x=1;x<(1 << h);x++){
		if(2*x < (1 << h)) l[x] = 2*x;
		if(2*x+1 < (1 << h)) r[x] = 2*x+1;
	}
	
	int cur = (1 << h);
	for(int x=1;x<(1 << h);x++){
		int pos = x;
		while(pos*2 < (1 << h)){
			pos *= 2;
		}
		
		if(cur <= sz && l[pos] == 0){
			l[pos] = cur++;
		}
	}
	
	for(int x=1;x<(1 << h);x++){
		int pos = x;
		while(pos*2 < (1 << h)){
			pos *= 2;
		}
		
		if(cur <= sz && r[pos] == 0){
			r[pos] = cur++;
		}
	}
	
	for(int x=1;x<=sz;x++){
		cout << w[x] << " " << l[x] << " " << r[x] << "\n";
	}
    return 0;
}

