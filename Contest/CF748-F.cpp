#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		int n, a, b;
		string s;
		cin >> n >> a >> b;
		cin >> s;
		
		vector<int> v;
		for(int x=0;x<n;x++){
			v.push_back((s[x] - '0'));
		}
		
		string ans(n, '?');
		int cnt = 1e9;
		
		ll backtrack[n+1][n+1][a][b];
		bool table[n+1][n+1][a][b];
		fill(**table[0], **table[n+1], false);
		fill(**backtrack[0], **backtrack[n+1], 0);
		
		table[0][0][0][0] = true;
		for(int x=0;x<n;x++){
			for(int i=0;i<=n;i++){
				int j = x+1-i;
				for(int y=0;y<a;y++){
					for(int z=0;z<b;z++){
						if(table[x][i][y][z]){
							if(i+1 <= n){
								table[x+1][i+1][(y*10 + v[x]) % a][z] = true;
								backtrack[x+1][i+1][(y*10 +v[x]) % a][z] = (backtrack[x][i][y][z] | (1ll << x));
							}
							if(j+1 <= n){
								table[x+1][i][y][(z*10 + v[x]) % b] = true;
								backtrack[x+1][i][y][(z*10 + v[x]) % b] = backtrack[x][i][y][z];
							}
						}
					}
				}
			}
		}
		
		for(int i=1;i<n;i++){
			int j = n-i;
			
			if(table[n][i][0][0]){
				if(cnt > abs(i-j)){
					cnt = abs(i-j);
					for(int x=0;x<n;x++){
						if(backtrack[n][i][0][0] & (1ll << x)){
							ans[x] = 'R';
						} else {
							ans[x] = 'B';
						}
					}
				}
			}
		}
		
		if(cnt == 1e9){
			cout << "-1\n";
			continue;
		}
		
		cout << ans << "\n";
	}

    return 0;
}

