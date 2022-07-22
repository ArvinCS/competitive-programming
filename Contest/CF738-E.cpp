#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 998244353

const int maxN = 55;
const int maxM = 1e5 + 5;

ll table[maxN][maxM], cnt[maxM];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, m;
	cin >> n >> m;
	
	pair<int, int> p[n+1];
	for(int x=1;x<=n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	ll ans = 0;
	for(int i=1;i<=m;i++){
		for(int y=0;y*i<=m;y++) table[0][y] = 1;
		
		for(int x=1;x<=n;x++){
			int mn = (p[x].first+i-1)/i;
			int mx = (p[x].second)/i;
			
			if(mx < mn){
				table[n][m/i] = 0;
				break;
			}
			
			for(int y=0;y*i<=m;y++){
				table[x][y] = (y-mn >= 0 ? table[x-1][y-mn] : 0) - (y-mx > 0 ? table[x-1][y-mx-1] : 0);
				if(table[x][y] < 0) table[x][y] += mod;
				
				if(y > 0){
					table[x][y] += table[x][y-1];
					table[x][y] %= mod;
				}
			}
		}
		
		cnt[i] = table[n][m/i];
	}
	
	for(int x=m;x>0;x--){
		for(int y=2*x;y<=m;y+=x){
			cnt[x] -= cnt[y];
			if(cnt[x] < 0) cnt[x] += mod;
		}
	}
	
	cout << cnt[1] << "\n";
    return 0;
}

