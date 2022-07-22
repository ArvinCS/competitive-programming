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

const int maxN = 1e3 + 5;

bool grid[maxN][maxN];
int n, m;

ll moveUp(short x, short y, int move){
	if(x < 0 || x >= n || y < 0 || y >= m) return 1ll;
	
	short pos[2];
	pos[0] = x; pos[1] = y;
	
	ll val = 0;
	while(pos[0] >= 0 && pos[1] >= 0 && grid[pos[0]][pos[1]]){
		val++;
		pos[move]--;
		move ^= 1;
	}
	
	return val;
}

ll moveDown(short x, short y, int move){
	if(x < 0 || x >= n || y < 0 || y >= m) return 1ll;
	
	short pos[2];
	pos[0] = x; pos[1] = y;
	
	ll val = 0;
	while(pos[0] < n && pos[1] < m && grid[pos[0]][pos[1]]){
		val++;
		pos[move]++;
		move ^= 1;
	}
	
	return val;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int q;
	cin >> n >> m >> q;
	
	fill(grid[0], grid[maxN], 1);
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			ans++;
			
			int a = n-1-x;
			int b = m-1-y;
			
			int mn = min(a+1, b);
			ans += mn + min(a, mn);
			
			mn = min(a, b+1);
			ans += mn + min(mn, b);
		}
	}
		
	while(q--){
		short a, b;
		cin >> a >> b;
		
		a--; b--;
		
		if(grid[a][b]){
			ll tmp1 = moveUp(a,b,0);
			ll tmp2 = moveUp(a,b,1);
			ll tmp3 = moveDown(a,b,0);
			ll tmp4 = moveDown(a,b,1);
			
			ans -= tmp1*tmp4 + tmp2*tmp3 - 1;
			
			grid[a][b] ^= 1;
		} else {
			grid[a][b] ^= 1;
			
			ll tmp1 = moveUp(a,b,0);
			ll tmp2 = moveUp(a,b,1);
			ll tmp3 = moveDown(a,b,0);
			ll tmp4 = moveDown(a,b,1);
			
			ans += tmp1*tmp4 + tmp2*tmp3 - 1;
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

