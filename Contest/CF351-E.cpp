#include <bits/stdc++.h>

using namespace std;

#define ll long long

const double eps = 1e-6;
const int maxN = 2e5 + 5;
const int maxK = 55;

double table[maxK][maxN];
double suffix[maxN], cnt[maxN];
ll t[maxN];
ll prefix[maxN];

void solve(int k, int l, int r, int optL, int optR){
	if(l > r) return;
	
	int m = (l+r) >> 1;
	
	if(min(optR, m) < optL) return;
	
	double best = 1e18;
	int optM = -1;
	for(int x=optL;x<=min(optR, m);x++){
		double val = (x > 0 ? table[k-1][x-1] : 1e18) + (suffix[x] - (suffix[m+1] + cnt[m+1]*(prefix[m] - (x > 0 ? prefix[x-1] : 0))));
		
		if((val-best) < eps){
			best = val;
			optM = x;
		}
	}
	
	solve(k, l, m-1, optL, optM);
	solve(k, m+1, r, optM, optR);
	
	table[k][m] = best;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	for(int x=0;x<n;x++){
		cin >> t[x];
	}
	
	prefix[0] = t[0];
	for(int x=1;x<n;x++){
		prefix[x] = (prefix[x-1] + t[x]);
	}
	
	cnt[n] = suffix[n] = 0;
	
	suffix[n-1] = 1;
	cnt[n-1] = 1.0/t[n-1];
	for(int x=n-2;x>=0;x--){
		cnt[x] = (1.0/t[x] + cnt[x+1]);
		suffix[x] = (t[x]*cnt[x] + suffix[x+1]);
	}
	
	fill(table[0], table[maxK], 1e18);
	
	table[1][0] = 1;
	for(int x=1;x<n;x++){
		table[1][x] = (table[1][x-1] + prefix[x]*1.0/t[x]);
	}
	
	for(int x=2;x<=k;x++){
		solve(x, 0, n-1, 0, n-1);
	}
	
	cout << fixed << setprecision(6) << table[k][n-1] << "\n";
    return 0;
}

