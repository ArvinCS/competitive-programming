#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 305;
const int maxM = 5e4;

ll table[maxN][maxN];
int w[maxM];
int L[maxM], R[maxM];
int n, m;
vector<int> v[maxN];
int cost[maxN][maxN][maxN];

ll solve(int l, int r){ // O(N^3)
	if(l > r) return 0;
	if(table[l][r] != -1) return table[l][r];
	
	ll ans = 0;
	for(int x=l;x<=r;x++){
		if(cost[l][r][x] > 0){
			ans = max(ans, cost[l][r][x]+solve(l, x-1)+solve(x+1, r));
		}
	}
	
	return table[l][r] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		cin >> w[x] >> L[x] >> R[x];
	}
	
	fill(*cost[0], *cost[n+1], 0);
	
	for(int x=0;x<m;x++){
		for(int k=L[x];k<=R[x];k++){
			cost[L[x]][R[x]][k] = max(cost[L[x]][R[x]][k], w[x]);
		}
	}
	for(int e=2;e<=n;e++){
		for(int l=1;l+e-1<=n;l++){
			int r = l+e-1;
			for(int k=l;k<=r;k++){
				cost[l][r][k] = max(cost[l][r][k], max(cost[l+1][r][k], cost[l][r-1][k]));
			}
		}
	}
	
	fill(table[0], table[n+1], -1);
	
	cout << solve(1, n) << "\n";
    return 0;
}

