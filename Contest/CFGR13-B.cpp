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
		int n, u, v;
		cin >> n >> u >> v;
		
		int data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		int ans = u+v;
		for(int x=0;x<n-1;x++){
			if(abs(data[x+1]-data[x]) > 1){
				ans = 0;
				break;
			}
		}
		for(int x=0;x<n-1;x++){
			if(abs(data[x+1]-data[x]) == 1){
				ans = min(ans, min(u, v));
			} else if(abs(data[x+1]-data[x]) == 0){
				ans = min(ans, 2*v);
			}
		}
		cout << ans << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

