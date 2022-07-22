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

const int maxN = 15e4 + 5;
const int logN = log2(maxN);

ll cost[4][maxN];
set<int> valid[4][maxN];
ll table[logN+1][maxN];
ll tmp[maxN];

void build(){
	for(int i=1;i<=logN;i++){
		int length = (1 << i);
		for(int y=0;y+length<=maxN;y++){
			table[i][y] = min(table[i-1][y], table[i-1][y+length/2]);
		}
	}
}

ll rmq(int l, int r){
	int lg = log2(r-l+1);
	int length = (1 << lg);
	return min(table[lg][l], table[lg][r-length+1]);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n[4];
	for(int x=0;x<4;x++) cin >> n[x];
	
	for(int x=0;x<4;x++){
		for(int y=0;y<n[x];y++){
			cin >> cost[x][y];
		}
	}
	
	for(int x=0;x<3;x++){
		int m;
		cin >> m;
		
		for(int y=0;y<m;y++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			valid[x][b].insert(a);
		}
	}
	
	for(int x=0;x<n[0];x++){
		table[0][x] = cost[0][x];
	}
	build();
	
	for(int i=0;i<3;i++){
		for(int x=0;x<n[i+1];x++){
			ll cur = cost[i+1][x];
			ll best = inf_ll;
			int left = 0;
			for(auto right : valid[i][x]){
				if(left < right) best = min(best, rmq(left, right-1));
				left = right+1;
			}
			if(left < n[i]) best = min(best, rmq(left, n[i]-1));
			
			tmp[x] = (valid[i][x].size() == n[i] || best == inf_ll ? inf_ll : cur+best);
		}
		
		for(int x=0;x<maxN;x++){
			table[0][x] = tmp[x];
		}
		build();
	}
	
	ll ans = rmq(0, n[3]-1);
	cout << (ans == inf_ll ? -1 : ans) << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

