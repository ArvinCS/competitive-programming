#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const int maxN = 505;

ll pw2[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	pw2[0] = 1;
	for(int x=1;x<maxN;x++){
		pw2[x] = (2 * pw2[x-1]) % mod;
	}
	
	int n, k;
	cin >> n >> k;
	
	ll table[n+1][k+1];
	fill(table[0], table[n+1], 0);
	
	auto add = [&](ll &a, ll b) -> void {
		a += b;
		if(a >= mod) a -= mod;
		if(a < 0) a += mod;
	};
	
	table[0][0] = 1;
	for(int x=1;x<=n;x++){
		// optimal:
		// tidak tumpang tindih dengan range dp optimal sebelumnya
		// tidak optimal:
		// tumpang tindih dengan range dp optimal sebelumnya
		
		// jika kasus nambah range yg optimal
		for(int y=0;y<x;y++){
			for(int z=0;z<k;z++){
				// kasus spesial tidak optimal yg digabung dgn dp optimal, yaitu:
				// kasus tidak optimal end rangenya sama dgn yg optimal
				add(table[x][z+1], table[y][z] * ((pw2[x-y]-1+mod)%mod) % mod * pw2[y] % mod);
			}
		}
		
		// jika kasus nambah range yg tidak optimal
		for(int y=1;y<x;y++){
			for(int z=1;z<=k;z++){
				table[y][z] *= pw2[y];
				table[y][z] %= mod;
			}
		}
	}
	
	ll ans = 0;
	for(int x=0;x<=n;x++){
		add(ans, table[x][k]);
	}
	
	cout << ans << "\n";
    return 0;
}

