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
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int pos[2*n+1];
		fill(pos, pos+2*n+1, inf_int);
		
		int a[n], b[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			pos[a[x]] = x;
		}
		for(int x=0;x<n;x++){
			cin >> b[x];
		}
		
		for(int x=1;x<=2*n;x++){
			pos[x] = min(pos[x], pos[x-1]);
		}
		
		int ans = inf_int;
		for(int x=0;x<n;x++){
			ans = min(ans, x+pos[b[x]]);
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

