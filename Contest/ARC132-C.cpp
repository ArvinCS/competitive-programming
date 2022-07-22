#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, d;
	cin >> n >> d;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		if(a[x] >= 1) a[x]--;
	}
	
	int bitlength = 2*d+1;
	int bitsz = (1 << bitlength);
	ll table[n+1][bitsz];
	fill(table[0], table[n+1], 0);
	
	table[0][0] = 1;
	for(int x=0;x<n;x++){
		for(int y=-d;y<=d;y++){
			int val = x+y;
			if(a[x] != -1 && a[x] != val) continue;
			if(x+y < 0 || x+y >= n) continue;
			
			for(int z=0;z<bitsz;z++){
				if((z >> 1)&(1 << (y+d))){
					continue;
				}
				
				table[x+1][(z >> 1)|(1 << (y+d))] += table[x][z];
				table[x+1][(z >> 1)|(1 << (y+d))] %= mod;
			}
		}
	}
	
	ll ans = 0;
	for(int z=0;z<bitsz;z++){
		ans += table[n][z];
		ans %= mod;
	}
	cout << ans << "\n";
    return 0;
}

