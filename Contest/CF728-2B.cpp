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
		
		int a[n+1], pos[2*n+5];
		fill(pos, pos+2*n+5, inf_int);
		
		for(int x=1;x<=n;x++){
			cin >> a[x];
		}
		
		ll ans = 0;
		for(int x=1;x<=n;x++){
			for(int y=1;y*a[x]<=2*n;y++){
//				cout << a[x] << " " << y << " " << pos[a[x]*y] << " " << a[x]*y-x  << "\n";
				if(pos[y] == a[x]*y-x){
//					cout << a[x] << " " << y << "\n";
					ans++;
				}
			}
			pos[a[x]] = x;
		}
		cout << ans << "\n";
	}
	
    return 0;
}

