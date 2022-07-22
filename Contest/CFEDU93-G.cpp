#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxA = 2e5 + 5;

bool exist[maxA], table[maxA];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, s, t;
	cin >> n >> s >> t;
	
	bool exist[s+1];
	fill(exist, exist+s+1, false);
	
	int a[n+1];
	for(int x=0;x<=n;x++){
		cin >> a[x];
		exist[a[x]] = true;
	}
	
	int b[n+1];
	int prv = 0;
	for(int x=0;x<=n;x++){
		b[x] = a[x] - prv;
		prv = a[x];
	}
	
	int q;
	cin >> q;
	
	int l[q];
	for(int x=0;x<q;x++){
		cin >> l[x];
	}
	
	int sz = cbrt(n*1ll*n)+1;
	int m = (n+sz-1)/sz;
	
	bool suffix[m][s+1], prefix[m][s+1];
	fill(suffix[0], suffix[m], false);
	fill(prefix[0], prefix[m], false);
	
	for(int x=0;x<m;x++){
		prefix[x][0] = true;
		
		ll cur = 0;
		for(int y=x*sz;y<min((x+1)*sz, n+1);y++){
			cur += b[y];
			prefix[x][y] = true;
		}
		
		cur = 0;
		suffix[x][cur] = true;
		for(int y=(x+1)*sz-1;y>=max((x-1)*sz+1, 0);y--){
			cur += b[y];
			suffix[x][y] = true;
		}
	}
	
	ll sum[m];
	fill(sum, sum+m, 0);
	
	for(int x=0;x<=n;x++){
		sum[x/sz] += b[x];
	}
	
	fill(table, table+maxA, false);
	
	for(int x=0;x<m;x++){
		ll cur = 0;
		for(int y=x;y<m;y++){
			cur += sum[y];
			
			fill(exist, exist+maxA, false);
			exist[0] = true;
			for(int z=0;z<maxA;z++){
				exist[z] |= (x > 0 ? prefix[x-1][z] : false);
			}
		}
	}
	
    return 0;
}

