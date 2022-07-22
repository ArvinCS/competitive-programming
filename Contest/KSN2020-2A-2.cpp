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

int table[105][21][21][21][21];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<int> cur(4, 4);
	for(int x=0;x<4;x++){
		cin >> cur[x];
	}
	
	bool mat[k+1][k+1];
	for(int x=1;x<=k;x++){
		for(int y=1;y<=k;y++){
			char tmp;
			cin >> tmp;
			
			mat[x][y] = (tmp - '0');
		}
	}
	
	pair<int, int> room[n];
	vector<int> mons, lib;
	lib.push_back(0);
	for(int x=0;x<n;x++){
		cin >> room[x].first;
		if(room[x].first == 1){
			cin >> room[x].second;
			mons.push_back(x);
		} else {
			room[x].second = 0;
			lib.push_back(x);
		}
	}
	mons.push_back(n);
	
	int suffix[n+1][k+1];
	fill(suffix[0], suffix[n+1], 0);
	
	suffix[n-1][room[n-1].second]++;
	for(int x=n-2;x>=0;x--){
		if(room[x].first == 1){
			for(short i=1;i<=k;i++){
				suffix[x][i] = suffix[x+1][i];
			}
			suffix[x][room[x].second]++;
		}
	}
	
	int ans = 0;
	sort(cur.begin(), cur.end());
	
	fill(table[0][0][0][0], table[105][0][0][0], -1);
	
	table[0][cur[0]][cur[1]][cur[2]][cur[3]] = 0;
	
	for(int z=1;z<=k;z++){
		for(int j=0;j<4;j++){
			if(mat[cur[j]][z]){
				table[0][cur[0]][cur[1]][cur[2]][cur[3]] += suffix[0][z];
				break;
			}
		}
	}
	
	if(lib.size() == 1){
		ans = max(ans, table[0][cur[0]][cur[1]][cur[2]][cur[3]]);
	}
	
	for(int x=1;x<lib.size();x++){
		for(int a=1;a<=k-3;a++){
			for(int b=a+1;b<=k-2;b++){
				for(int c=b+1;c<=k-1;c++){
					for(int d=c+1;d<=k;d++){					
						int skills[4] = {a, b, c, d};
						int score = -1;
						for(int i=0;i<4;i++){
							for(int y=1;y<=k;y++){
								int tmp[4] = {a, b, c, d};
								tmp[i] = y;
								sort(tmp, tmp+4);
								if(table[x-1][tmp[0]][tmp[1]][tmp[2]][tmp[3]] >= 0){
									score = max(score, table[x-1][tmp[0]][tmp[1]][tmp[2]][tmp[3]]);
								}
							}
						}
						
						if(score == -1){
							continue;
						}
						
//						cout << a << " " << b << " " << c << " " << d << "\n";	
						int last = *upper_bound(mons.begin(), mons.end(), lib[x]);
						int cnt = 0;
												
						if(last < n && lib[x]+1 == last){
							for(int y=1;y<=k;y++){
								for(int i=0;i<4;i++){
									if(mat[skills[i]][y]){
										cnt += suffix[last][y];
										break;
									}
								}
							}
						}
						
//						cout << x << " -> " << score << " " << score+cnt << "\n";
						table[x][skills[0]][skills[1]][skills[2]][skills[3]] = max(table[x][skills[0]][skills[1]][skills[2]][skills[3]], score+cnt);
						
						if(x+1 == lib.size()){
							ans = max(ans, table[x][skills[0]][skills[1]][skills[2]][skills[3]]);
						}
					}
				}
			}
		}
	}

	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

