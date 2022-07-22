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

const int maxM = 105;

ll n, m;

void multiply(ll a[maxM][maxM], ll b[maxM][maxM]){
	ll ans[maxM][maxM];
	fill(ans[0], ans[maxM], 0);
	
	for(int x=0;x<m;x++){
		for(int y=0;y<m;y++){
			for(int z=0;z<m;z++){
				ans[x][z] += (a[x][y] * b[y][z]) % mod;
				ans[x][z] %= mod;
			}
		}
	}
	
	for(int x=0;x<maxM;x++){
		for(int y=0;y<maxM;y++){
			a[x][y] = ans[x][y];
		}
	}
}

ll powmod(ll mat[maxM][maxM], ll y){	
	ll ans[maxM][maxM];
	fill(ans[0], ans[maxM], 0);
	
	for(int x=0;x<m;x++){
		for(int y=0;y<m;y++){
			ans[x][y] = mat[x][y];
		}
	}
	
	while(y > 0){
		if(y&1){
			multiply(ans, mat);
		}
		
		y >>= 1;
		multiply(mat, mat);
	}
	
	ll sum = 0;
	for(int x=0;x<m;x++){
		sum += ans[0][x];
		sum %= mod;
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n >> m;
	
	if(n < m){
		cout << "1\n";
		return 0;
	}
	
	ll mat[maxM][maxM];
	for(int x=0;x<m;x++){
		for(int y=0;y<m;y++){
			if(x == 0){
				if(y == 0 || y == m-1) mat[x][y] = 1;
				else mat[x][y] = 0;
			} else {
				mat[x][y] = (y == x-1 ? 1 : 0);
			}
		}
	}
	
	cout << powmod(mat, n-m) << "\n";
    return 0;
}

