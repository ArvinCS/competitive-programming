#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;
const ll mxbit = (1 << 10);

ll table[10][mxbit][10][2];
ll new_table[10][mxbit][10][2];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	fill(**table[0], **table[10], 0);
	
	for(int i=0;i<m;i++){
		table[i][0][m-1][0] = 1;
	}
	for(int x=1;x<n;x++){
		fill(**new_table[0], **new_table[10], 0);
		
		for(int l=0;l<m;l++){
			for(int bit=0;bit<mxbit;bit++){
				for(int mn=l;mn<m;mn++){
					if(bit == 0){
						for(int i=l+1;i<m;i++){
							new_table[l][bit|(1 << i)][mn][0] += table[l][bit][mn][0];
							if(new_table[l][bit|(1 << i)][mn][0] >= mod) new_table[l][bit|(1 << i)][mn][0] -= mod;
						}
						for(int i=0;i<l;i++){
							new_table[i][bit][mn][0] += table[l][bit][mn][0];
							if(new_table[i][bit][mn][0] >= mod) new_table[i][bit][mn][0] -= mod;
						}
					} else {
						// cases for num < l
						for(int i=0;i<l;i++){
							for(int v=0;v<2;v++){
								new_table[i][bit][mn][v] += table[l][bit][mn][v];
								if(new_table[i][bit][mn][v] >= mod) new_table[i][bit][mn][v] -= mod;
							}
						}
						
						int r = log2(bit);
						// cases for l < num <= r 
						for(int v=0;v<2;v++){
							int cnt = 0;
							for(int i=l+1;i<=r;i++){
								if(v == 1 && cnt >= 2 && mn < i) break;
								
								new_table[l][bit|(1 << i)][min(mn, (cnt ? i : mn))][v|cnt] += table[l][bit][mn][v];
								if(new_table[l][bit|(1 << i)][min(mn, (cnt ? i : mn))][v|cnt] >= mod) new_table[l][bit|(1 << i)][min(mn, (cnt ? i : mn))][v|cnt] -= mod;
								if(bit&(1 << i)) cnt++;
							}
						}
						
						// cases for r < num
						for(int i=r+1;i<m;i++){							
							for(int v=0;v<1;v++){
								new_table[l][bit|(1 << i)][min(mn, (bit != 0 ? i : mn))][v|(bit != 0)] += table[l][bit][mn][v];
								if(new_table[l][bit|(1 << i)][min(mn, (bit != 0 ? i : mn))][v|(bit != 0)] >= mod) new_table[l][bit|(1 << i)][min(mn, (bit != 0 ? i : mn))][v|(bit != 0)] -= mod;
							}
						}
					}
					
					// cases for num == l
					for(int v=0;v<2;v++){
						new_table[l][bit][mn][v] += table[l][bit][mn][v];
						if(new_table[l][bit][mn][v] >= mod) new_table[l][bit][mn][v] -= mod;
					}
				}
			}
		}
		
		for(int i=0;i<m;i++){
			for(int j=0;j<mxbit;j++){
				for(int k=i;k<m;k++){
					for(int v=0;v<2;v++){
						table[i][j][k][v] = new_table[i][j][k][v];
					}
				}
			}
		}
	}
	
	ll ans = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<mxbit;j++){
			for(int k=i;k<m;k++){
				ans += table[i][j][k][1];
				if(ans >= mod) ans -= mod;
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

