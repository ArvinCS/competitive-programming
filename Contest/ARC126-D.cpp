#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 205;
const int maxK = 16;

int prefix[maxN][(1 << maxK)], suffix[maxN][(1 << maxK)];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		a[x]--;
	}
	
	fill(prefix[0], prefix[maxN], 1e9);
	fill(suffix[0], suffix[maxN], 1e9);
	
	prefix[0][0] = 0;
	suffix[n][0] = 0;
	
	int ans = 1e9;
	for(int x=0;x<n;x++){
		for(int y=0;y<(1 << k);y++){
			int cntLeft = 0, cntRight = 0;
			for(int i=0;i<k;i++){
				if(y&(1 << i)){
					if(i <= a[x]) cntLeft++;
					else if(i > a[x]) cntRight++;
				}
			}
			
			prefix[x+1][y] = min(prefix[x+1][y], prefix[x][y]+cntLeft+cntRight);
			if(!(y&(1 << a[x]))){
				prefix[x+1][y|(1 << a[x])] = min(prefix[x+1][y|(1 << a[x])], prefix[x][y]+cntRight);
			}
		}
	}
	
	for(int x=n-1;x>0;x--){
		for(int y=0;y<(1 << k);y++){
			int cntLeft = 0, cntRight = 0;
			for(int i=0;i<k;i++){
				if(y&(1 << i)){
					if(i <= a[x]) cntLeft++;
					else if(i > a[x]) cntRight++;
				}
			}
			
			suffix[x][y] = min(suffix[x][y], suffix[x+1][y]+cntLeft+cntRight);
			if(!(y&(1 << a[x]))){
				suffix[x][y|(1 << a[x])] = min(suffix[x][y|(1 << a[x])], suffix[x+1][y]+cntLeft);
			}
		}
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<(1 << k);y++){
			int z = ((1 << k)-1)^y;
			int cnt = 0, cur = 0;
			
			for(int i=k-1;i>=0;i--){
				if(y&(1 << i)) cur++;
				if(z&(1 << i)){
					cnt += cur;
				}
			}
			
			ans = min(ans, prefix[x][y]+suffix[x][z]+cnt);
		}
	}
	
	cout << ans << "\n";
    return 0;
}
