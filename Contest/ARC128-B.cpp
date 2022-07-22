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
	
	int t;
	cin >> t;
	
	while(t--){
		int c[3];
		for(int x=0;x<3;x++){
			cin >> c[x];
		}
		
		sort(c, c+3);
		
		int ans = inf_int;
		for(int x=0;x<3;x++){
			for(int y=x+1;y<3;y++){
				if((c[y]-c[x]) % 3 == 0){
					ans = min(ans, c[y]);
				}
			}
		}
		
		cout << (ans != inf_int ? ans : -1) << "\n";
	}
	
    return 0;
}

