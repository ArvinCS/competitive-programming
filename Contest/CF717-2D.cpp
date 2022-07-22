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

const int maxN = 1e5 + 5;
const int logN = log2(maxN) + 1;

ll data[maxN];
int last[maxN], factor[maxN], prime[maxN];
int table[logN][maxN], dp[logN][maxN];

void build(){
	for(int x=0;x<maxN;x++){
		table[0][x] = last[x];
	}	
	for(int i=1;i<logN;i++){
		int length = (1 << i);
		for(int x=0;x+length<=maxN;x++){
			table[i][x] = max(table[i-1][x], table[i-1][x+length/2]);
		}
	}
}

int rmq(int left, int right){
	int lg = log2(right-left+1);
	int length = (1 << lg);
	
	return max(table[lg][left], table[lg][right-length+1]);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	pair<int, int> q[n];
	for(int x=0;x<m;x++){
		int left, right;
		cin >> left >> right;
		
		left--; right--;
		q[x] = {left, right};
	}
	
	for(int x=0;x<maxN;x++) prime[x] = x;
	for(int x=2;x*x<maxN;x++){
		if(prime[x] == x){
			for(int y=x+x;y<maxN;y+=x){
				if(prime[y] == y) prime[y] = x;
			}
		}
	}
	
	fill(factor, factor+maxN, -1);	
	for(int x=0;x<n;x++){
		int mx = -1;
		ll cur = data[x];
		while(cur > 1){
			ll div = prime[cur];
			
			mx = max(mx, factor[div]);
			while(cur % div == 0){
				cur /= div;
			}
			
			factor[div] = x;
		}
		last[x] = mx;
	}
	
	build();

	for(int x=0;x<n;x++){
		dp[0][x] = rmq(0, x);
	}
	
	for(int x=1;x<logN;x++){
		for(int y=0;y<n;y++){
			if(dp[x-1][y] >= 0) dp[x][y] = dp[x-1][dp[x-1][y]];	
			else dp[x][y] = -1;	
		}
	}

	for(int x=0;x<m;x++){		
		int left = q[x].first, right = q[x].second;
		
		int ans = 0;
		for(int i=logN-1;i>=0;i--){
			if(dp[i][right] >= left){
				ans += (1 << i);
//				cout << right << " " << dp[i][right] << "\n";
				right = dp[i][right];
			}
		}
		cout << ans+1 << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

