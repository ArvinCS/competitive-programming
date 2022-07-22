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
		
		string a, b;
		cin >> a >> b;
		
		bool one = false, pass = false;
		int ans = 0;
		for(int x=0;x<n;x++){
			if(pass){
				pass = false;				
				continue;
			}
			if(a[x] != b[x]){
				ans += 2;
				one = false;
			} else {
				if(a[x] == '1'){
					one = true;
				} else {
					if(one){
						ans += 2;
						one = false;
					} else {
						if(x+1 < n && a[x+1] == b[x+1] && a[x+1] == '1'){
							ans += 2;
							pass = true;
						} else {
							ans++;
						}
					}
				}
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

