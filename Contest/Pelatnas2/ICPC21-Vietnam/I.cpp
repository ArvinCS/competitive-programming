#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll table[51][16][16][16][16][16];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	map<string, int> mp;
	mp["dp"] = 0; mp["graph"] = 1; mp["mathgeo"] = 2; mp["ds"] = 3; mp["adhoc"] = 4;
	
	int n;
	cin >> n;
	
	int cnt[n][5];
	fill(cnt[0], cnt[n], 0);
	
	for(int x=0;x<n;x++){
		int t;
		cin >> t;
		
		for(int y=0;y<t;y++){
			string s;
			cin >> s;
			
			cnt[x][mp[s]] = 1;
		}
	}
	
	int mx = 0;
	int l[5], r[5];
	for(int x=0;x<5;x++){
		cin >> l[x] >> r[x];
		assert(l[x] <= 17 && r[x] <= 17);
		mx = max(mx, l[x]);
	}
	
	for(int x=0;x<=n;x++){
		for(int a=0;a<=r[0];a++){
			for(int b=0;b<=r[1];b++){
				for(int c=0;c<=r[2];c++){
					for(int d=0;d<=r[3];d++){
						for(int e=0;e<=r[4];e++){
							table[x][a][b][c][d][e] = 0;
						}
					}
				}
			}
		}
	}
	
	table[0][0][0][0][0][0] = 1;
	for(int x=0;x<n;x++){
		for(int a=0;a<=r[0];a++){
			for(int b=0;b<=r[1];b++){
				for(int c=0;c<=r[2];c++){
					for(int d=0;d<=r[3];d++){
						for(int e=0;e<=r[4];e++){
							int new_a = a+cnt[x][0];
							int new_b = b+cnt[x][1];
							int new_c = c+cnt[x][2];
							int new_d = d+cnt[x][3];
							int new_e = e+cnt[x][4];
							
							if(new_a <= r[0] && new_b <= r[1] && new_c <= r[2] && new_d <= r[3] && new_e <= r[4]){
								table[x+1][new_a][new_b][new_c][new_d][new_e] += table[x][a][b][c][d][e];
							}
							
							table[x+1][a][b][c][d][e] += table[x][a][b][c][d][e];
						}
					}
				}
			}
		}
	}
	
	ll ans = -(mx == 0 ? 1 : 0);
	for(int a=l[0];a<=r[0];a++){
		for(int b=l[1];b<=r[1];b++){
			for(int c=l[2];c<=r[2];c++){
				for(int d=l[3];d<=r[3];d++){
					for(int e=l[4];e<=r[4];e++){
						ans += table[n][a][b][c][d][e];
					}
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
