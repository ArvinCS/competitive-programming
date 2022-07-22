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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	int p[n];
	for(int x=0;x<n;x++){
		cin >> p[x];
	}
	
	int prefix[n][2], suffix[n][2];
	fill(prefix[0], prefix[n], 0);
	fill(suffix[0], suffix[n], 0);
	
	for(int x=1;x<n;x++){
		if(v[x] > v[x-1]){
			prefix[x][0] = prefix[x-1][0] + 1;
		}
	}
	for(int x=n-2;x>=0;x--){
		if(v[x] > v[x+1]){
			suffix[x][0] = suffix[x+1][0] + 1;
		}
	}
	
	for(int x=1;x<n;x++){
		if(v[x] < v[x-1]){
			prefix[x][1] = prefix[x-1][1] + 1;
		}
	}
	for(int x=n-2;x>=0;x--){
		if(v[x] < v[x+1]){
			suffix[x][1] = suffix[x+1][1] + 1;
		}
	}
	
	int premax[n], sufmax[n];
	for(int x=0;x<n;x++){
		premax[x] = max(x == 0 ? 0 : premax[x-1], max(prefix[x][1], suffix[x][1]));
	}
	for(int x=n-1;x>=0;x--){
		sufmax[x] = max(x == n-1 ? 0 : sufmax[x+1], max(prefix[x][1], suffix[x][1]));
	}
	
	ll ans = 0;
	for(int x=1;x<n-1;x++){
		if(p[x-1] < p[x] && p[x] > p[x+1]){
			if(x-prefix[x][0]-1 >= 0 && prefix[x][0] < premax[x-prefix[x][0]-1]){
				continue;
			}
			if(x+1 < n && suffix[x][0] < premax[x-suffix[x][0]-1]){
				continue;
			}
			
			ans++;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

