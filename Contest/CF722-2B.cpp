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
		
		ll data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		sort(data, data+n);
		
		ll mx = 1, mn = inf_ll;
		for(int x=1;x<n;x++){
			mn = min(data[x]-data[x-1], mn);
			if(mn >= data[x]){
				mx++;
			} else {
				break;
			}
		}
		cout << mx << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

