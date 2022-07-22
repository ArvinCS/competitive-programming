#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

const int maxN = 55;

bool table[maxN][maxN];
ll prefix[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, k;
	cin >> n >> k;
	
	ll data[n+1];
	for(int x=1;x<=n;x++){
		cin >> data[x];
	}
	
	prefix[0] = 0;
	for(int x=1;x<=n;x++) prefix[x] = data[x] + prefix[x-1];
		
	ll mask = 0;
	for(ll bit=60;bit>=0;bit--){
		fill(table[0], table[maxN], false);
		
		ll tmp = mask | (1ll << bit);
		for(int x=1;x<=n;x++) table[1][x] = ((prefix[x]&tmp) == tmp);
		for(int i=2;i<=k;i++){
			for(int x=i;x<=n;x++){
				for(int y=0;y<x;y++){
					ll total = prefix[x] - prefix[y];
					if((total&tmp) == tmp){
						if(table[i-1][y]) table[i][x] = true;
					}
				}
			}
		}
		
		if(table[k][n]){
//			cout << bit << " -> " << tmp << "\n";
			mask = tmp;
		}
	}
	
	cout << mask << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

