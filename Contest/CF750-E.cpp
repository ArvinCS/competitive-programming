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

ll a[maxN], suffix[maxN];
ll mx[505][maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		suffix[n] = 0;
		for(int x=n-1;x>=0;x--){
			suffix[x] = a[x] + suffix[x+1];
		}
		
		mx[1][n] = -1;
		for(int x=n-1;x>=0;x--){
			mx[1][x] = max(a[x], mx[1][x+1]);
		}
		
		int ans = 1;
		for(int x=2;x<=500;x++){
			if(x*(x+1)/2 > n) break;
			
			bool found = false;
			
			for(int y=n;y>=max(0, n-x);y--){
				mx[x][y] = -1;
			}
			for(int y=n-x;y>=0;y--){
				ll sum = suffix[y] - suffix[y+x];
				if(mx[x-1][y+x] > sum){
					found = true;
					mx[x][y] = sum;
				} else {
					mx[x][y] = -1;
				}
				
				mx[x][y] = max(mx[x][y], mx[x][y+1]);
			}
			
			if(!found){
				break;
			}
			
			ans = x;
		}
		
		cout << ans << "\n";
	}

    return 0;
}

