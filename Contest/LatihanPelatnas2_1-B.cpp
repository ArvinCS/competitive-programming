#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		ll x, y;
		cin >> x >> y;
		
		ll ans = 0;
		int mxX = (x > 0 ? log2(x) : -1), mxY = (y > 0 ? log2(y) : -1);
		
		ll table[31][2][2];
		fill(*table[0], *table[31], 0);

		for(int i=0;i<=30;i++){
			int bit = (1 << i);
			
			for(int j=0;j<2;j++){
				for(int k=0;k<2;k++){
					if(i <= mxX){
						if(j == 1){
							if(x&bit){
								table[i][j][k] += (i > 0 ? table[i-1][j][k^(k == 1 && (y&bit) != 0)] : 1); // if i-th bit of A is set
								table[i][j][k] %= mod;
							}
						} else {
							table[i][j][k] += (i > 0 ? table[i-1][j][k^(k == 1 && (y&bit) != 0)] : 1); // if i-th bit of A is set
							table[i][j][k] %= mod;
						}
					}
					
					if(i <= mxY){
						if(k == 1){
							if(y&bit){
								table[i][j][k] += (i > 0 ? table[i-1][j^(j == 1 && (x&bit) != 0)][k] : 1); // if i-th bit of A is set
								table[i][j][k] %= mod;
							}
						} else {
							table[i][j][k] += (i > 0 ? table[i-1][j^(j == 1 && (x&bit) != 0)][k] : 1); // if i-th bit of A is set
							table[i][j][k] %= mod;
						}
					}
					
					table[i][j][k] += (i > 0 ? table[i-1][j^(j == 1 && (x&bit) != 0)][k^(k == 1 && (y&bit) != 0)] : 1);
					table[i][j][k] %= mod;
				}
			}
		}
		
		ll prefix[32][2][2];
		fill(*prefix[0], *prefix[32], 0);
		
		for(int i=max(mxX, mxY);i>=-1;i--){
			for(int j=0;j<2;j++){
				if(i <= mxX){
					ans += prefix[i+1][j][1] * (i > 0 ? table[i-1][(i == mxX)][j^(j == 1 && (y&(1 << i)) != 0)] : 1) % mod;
					ans %= mod;
				}
				
				if(i <= mxY){
					ans += prefix[i+1][j][0] * (i > 0 ? table[i-1][j^(j == 1 && (x&(1 << i)) != 0)][(i == mxY)] : 1) % mod;
					ans %= mod;
				}
			}
			
			if(i >= 0){
				int bit = (1 << i);
				for(int j=0;j<2;j++){
					if(i <= mxX){
						if(j == 1){
							if(x&bit){
								prefix[i][j][0] += prefix[i+1][j][0];
								prefix[i][j^1][0] += prefix[i+1][j][0];
								
								prefix[i][j][0] %= mod;
								prefix[i][j^1][0] %= mod;
							} else {
								prefix[i][j][0] += prefix[i+1][j][0];
								prefix[i][j][0] %= mod;
							}
						} else {
							prefix[i][j][0] += 2ll*prefix[i+1][j][0] % mod;
							prefix[i][j][0] %= mod;
						}
					}
					
					if(i <= mxY){
						if(j == 1){
							if(y&bit){
								prefix[i][j][1] += prefix[i+1][j][1];
								prefix[i][j^1][1] += prefix[i+1][j][1];
								
								prefix[i][j][1] %= mod;
								prefix[i][j^1][1] %= mod;
							} else {
								prefix[i][j][1] += prefix[i+1][j][1];
								prefix[i][j][1] %= mod;
							}
						} else {
							prefix[i][j][1] += 2ll*prefix[i+1][j][1] % mod;
							prefix[i][j][1] %= mod;
						}
					}
				}
				
				if(i <= mxX){
					if(i == mxX){
						prefix[i][1][0] += i+1;
						prefix[i][1][0] %= mod;
					} else {
						prefix[i][0][0] += i+1;
						prefix[i][0][0] %= mod;
					}
				}
				
				if(i <= mxY){
					if(i == mxY){
						prefix[i][1][1] += i+1;
						prefix[i][1][1] %= mod;
					} else {
						prefix[i][0][1] += i+1;
						prefix[i][0][1] %= mod;
					}
				}
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

