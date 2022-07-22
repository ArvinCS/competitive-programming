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
	
	int n, m, k;
	cin >> n >> m >> k;
	
	int a[n+1][m+1];
	for(int x=1;x<=n;x++){
		for(int y=1;y<=m;y++){
			cin >> a[x][y];
		}
	}
	
	ll prefix[n+1][m+1];
	fill(prefix[0], prefix[n+1], 0);
	
	for(int x=1;x<=n;x++){
		ll sum = 0;
		for(int y=1;y<=m;y++){
			sum += a[x][y];
			
			prefix[x][y] = sum + prefix[x-1][y];
		}
	}
	
	ll best = inf_ll, x1 = -1, y1 = -1, x2 = -1, y2 = -1;
	for(int x=1;x<=n;x++){
		for(int y=1;y<=m;y++){
			int l1 = y, r1 = m;
			while(l1 <= r1){
				int m1 = (l1+r1) >> 1;
				
				int l2 = x, r2 = n, pos2 = inf_int;
				ll mn = inf_ll;
				while(l2 <= r2){
					int m2 = (l2+r2) >> 1;
					
					ll sum = prefix[m2][m1] - prefix[x-1][m1] - prefix[m2][y-1] + prefix[x-1][y-1];
					if(sum > k){
						if(mn > sum){
							mn = sum;
							pos2 = m2;
						}
						
						r2 = m2-1;
					} else {
						l2 = m2+1;
					}
				}
				
				if(mn > k && mn < inf_ll){
					if(best > mn){
						best = mn;
						x1 = x; y1 = y;
						x2 = pos2; y2 = m1;
					}
					
					r1 = m1-1;
				} else {
					l1 = m1+1;
				}
			}
		}
	}
	
	cout << (best+k-1)/k << "\n";
	cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
    return 0;
}

