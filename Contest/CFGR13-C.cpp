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
		ll n;
		cin >> n;
		
		ll data[n], table[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
			table[x] = 0;
		}
		
		ll ans = 0;
		for(int x=0;x<n;x++){
			ll cur = table[x];
			if(cur<data[x]-1){
				ans += data[x]-1-cur;
				cur += data[x]-1-cur;
			}
			
			if(x+1 < n) table[x+1] += cur-data[x]+1;
			if(x+2 < n){
				for(int y=x+2;y<min(n, x+data[x]+1);y++){
					table[y]++;
				}
			}
		}
		
//		for(int x=0;x<n;x++){
//			if(x > 0) cout << " ";
//			cout << table[x];
//		}
//		cout << "\n";
		cout << ans << "\n";
	}
 
    return 0;
}
 
// Santai
// Pikirin dengan benar-benar
