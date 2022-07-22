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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	string s;
	cin >> s;
	
	int cnt[n][2];
	bool table[n][1005];	
	
	for(int k=1;k<=n;k++){
		fill(cnt[0], cnt[n], 0);
		fill(table[0], table[n], false);
		
		for(int x=0;x<k;x++){
			int cur = x;
			while(cur < n){
				cnt[x][(s[cur] - '0')]++;
				cur += k;
			}
		}
		
		table[0][cnt[0][0]] = table[0][cnt[0][1]] = true;
		for(int x=1;x<k;x++){
			for(int y=0;y<=m;y++){
				if(y+cnt[x][0] <= m) table[x][y+cnt[x][0]] |= table[x-1][y];
				if(y+cnt[x][1] <= m) table[x][y+cnt[x][1]] |= table[x-1][y];
			}
		}
		
		if(table[k-1][m]){
			cout << k << "\n";
			return 0;
		}
	}
	
	cout << "-1\n";
    return 0;
}

