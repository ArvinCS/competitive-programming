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
		
		ll a[n], b[n], c[n];
		for(int x=0;x<n;x++){
			cin >> a[x] >> b[x];
		}
		for(int x=0;x<n;x++){
			cin >> c[x];
		}
		
		ll time = a[0] + c[0];
		for(int x=0;x<n-1;x++){
			time = max(b[x], time+(b[x]-a[x]+1)/2);
			
			ll need = a[x+1] - b[x] + c[x+1];			
			time += need;
		}
		cout << time << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

