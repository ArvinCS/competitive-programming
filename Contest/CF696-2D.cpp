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
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		bool negative = false;
		ll prefix[n], suffix[n+1];
		prefix[0] = 0;
		suffix[n] = 0;
		for(int x=0;x<n;x++){
			if(x > 0 && prefix[x-1] == -1){
				prefix[x] = -1;
				continue;
			}
			
			prefix[x] = (a[x] - (x > 0 ? prefix[x-1] : 0));
			if(prefix[x] < 0) prefix[x] = -1;
		}
		for(int x=n-1;x>=0;x--){
			if(suffix[x+1] == -1){
				suffix[x] = -1;
				continue;
			}
			
			suffix[x] = (a[x] - suffix[x+1]);
			if(suffix[x] < 0) suffix[x] = -1;
		}
		
		bool possible = false;
		for(int x=0;x+1<n;x++){
			ll prv = (x > 0 ? prefix[x-1] : 0);
			ll nxt = suffix[x+2];
			
			if(prv == -1 || nxt == -1) continue;
			if((a[x]-nxt)-(a[x+1] - prv) == 0 && nxt >= 0 && a[x]-nxt >= 0 && a[x+1]-prv >= 0 && prv >= 0){
				possible = true;
				break;
			}
		}
//		cout << diff << "\n";
		if(possible || (prefix[n-1] == 0 && !negative)) cout << "YES\n";
		else cout << "NO\n";
	}

    return 0;
}

