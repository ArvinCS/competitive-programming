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
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int data[n], mn = inf_int, mx = 0;
		for(int x=0;x<n;x++){
			cin >> data[x];
			mn = min(mn, data[x]);
			mx = max(mx, data[x]);
		}
		
		int ans = inf_int;
		
		bool exist[n+1];
		fill(exist, exist+n+1, false);
		for(int y=n-1;y>=0;y--){
			exist[data[y]] = true;
			if(exist[mn] && exist[mx]) ans = min(ans, n-y);
		}
		for(int y=n-1;y>=0;y--){
			exist[data[y]] = false;
		}
		
		for(int x=0;x<n;x++){
			exist[data[x]] = true;
			
			if(exist[mn] && exist[mx]) ans = min(ans, x+1);
			
			for(int y=n-1;y>x;y--){
				exist[data[y]] = true;
				if(exist[mn] && exist[mx]) ans = min(ans, x+1+(n-y));
			}
			
			for(int y=n-1;y>x;y--){
				exist[data[y]] = false;
			}
		}
		
		cout << ans << "\n";
	}

    return 0;
}



