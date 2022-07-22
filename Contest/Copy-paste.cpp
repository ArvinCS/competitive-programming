#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		us n, k;
		cin >> n >> k;
		
		short data[n];
		for(us x=0;x<n;x++) cin >> data[x];
		
		sort(data, data+n);
		ll ans = 0;
		for(us x=1;x<n;x++){
			ans += (k-data[x])/data[0];
		}	
		cout << ans << "\n";
	}
	
    return 0;
}

