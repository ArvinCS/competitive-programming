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

const int maxN = 1e7 + 5;

int primes[maxN], ans[maxN];
ll table[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	for(int x=1;x<maxN;x++){
		primes[x] = x;
		ans[x] = -1;
	}
	
	for(int x=2;x*x<maxN;x++){
		if(primes[x] == x){
			for(int y=x+x;y<maxN;y+=x){
				if(primes[y] == y){
					primes[y] = x;
				}
			}
		}
	}
	
	table[1] = 1;
	for(int x=2;x<maxN;x++){
		if(primes[x] == x){
			table[x] = x+1;
		} else {
			int cur = x;
			table[x] = 1;
			while(cur % primes[x] == 0){
				cur /= primes[x];
				table[x] = table[x] * primes[x] + 1;
			}
			table[x] *= table[cur];
		}
	}
	
	for(int x=maxN-1;x>=1;x--){
		if(table[x] < maxN) ans[table[x]] = x;
	}
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		cout << ans[n] << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

