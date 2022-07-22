#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const int maxN = 1e6 + 5;
const ll div2 = 500000004;
const int logN = 20;
const int maxD = 1e6 + 5;

int prime[maxN];
ll f[maxD][logN];

void chadd(ll &a, ll b){
	if(b >= mod) b -= mod;
	
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	for(int x=0;x<logN;x++){
		f[0][x] = (x > 0 ? 2 : 1);
	}
	for(int x=1;x<maxD;x++){
		for(int y=0;y<logN;y++){
			f[x][y] = 0;
			for(int z=0;z<=y;z++){
				chadd(f[x][y], f[x-1][z]);
			}
		}
	}
	
	for(int x=0;x<maxN;x++) prime[x] = x;
	for(int x=2;x*x<maxN;x++){
		if(prime[x] == x){
			for(int y=2*x;y<maxN;y+=x){
				if(prime[y] == y){
					prime[y] = x;
				}
			}
		}
	}
	
	int q;
	cin >> q;
	
	for(int i=0;i<q;i++){
		int d, n;
		cin >> d >> n;
		
		ll ans = 1;
		while(n > 1){
			int val = prime[n];
			int cnt = 0;
			
			while(n%val == 0){
				n /= val;
				cnt++;
			}
			
			ans *= f[d][cnt];
			ans %= mod;
		}
		
		cout << ans << "\n";
	}
    return 0;
}

