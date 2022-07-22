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

const int maxN = 2 * 1e5 + 10;

int a[maxN], b[maxN], pos[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		for(int x=0;x<n;x++){
			cin >> a[x];
			pos[a[x]] = x;
		}
		for(int x=0;x<k;x++){
			cin >> b[x];
		}
		
		bool valid[n];
		fill(valid, valid+n, true);
		for(int x=0;x<k;x++){
			valid[pos[b[x]]] = false;
		}
		
		ll ans = 1;
		for(int x=0;x<k;x++){
			int p = pos[b[x]];
			if(p > 0 && p < n-1){
				if(valid[p-1] && valid[p+1]) ans = (ans * 2) % smod;
				else if(!valid[p-1] && !valid[p+1]){
					ans = 0;
					break;
				}
			} else if(p > 0){
				if(!valid[p-1]){
					ans = 0;
					break;
				}
			} else {
				if(!valid[p+1]){
					ans = 0;
					break;
				}
			}
			valid[p] = true;
		}
		cout << ans << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

