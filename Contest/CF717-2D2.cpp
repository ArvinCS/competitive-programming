#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;
const int logN = log2(maxN)+1;

int jump[logN][maxN];
int prime[maxN], lst[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	for(int x=0;x<maxN;x++){
		prime[x] = x;
	}
	for(int x=2;x*x<maxN;x++){
		if(prime[x] == x){
			for(int y=2*x;y<maxN;y+=x){
				if(prime[y] == y){
					prime[y] = x;
				}
			}
		}
	}
	
	int n, q;
	cin >> n >> q;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	for(int x=0;x<maxN;x++){
		lst[x] = n;
	}
	for(int x=0;x<logN;x++){
		jump[x][n] = n;
	}
	
	int nxt = n;
	for(int x=n-1;x>=0;x--){
		int cur = a[x];
		while(cur > 1){
			int div = prime[cur];
			nxt = min(nxt, lst[div]);
			
			while(cur%div == 0) cur /= div;
			
			lst[div] = x;
		}
		
		jump[0][x] = nxt;
		for(int y=1;y<logN;y++){
			jump[y][x] = jump[y-1][jump[y-1][x]];
		}
	}
	
	while(q--){
		int l, r;
		cin >> l >> r;
		
		l--; r--;
		
		int ans = 1;
		int pos = l;
		for(int x=logN-1;x>=0;x--){
			if(jump[x][pos] <= r){
				pos = jump[x][pos];
				ans += (1 << x);
			}
		}
		
		cout << ans << "\n";
	}
    return 0;
}

