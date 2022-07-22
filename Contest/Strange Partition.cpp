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
	
	us t;
	cin >> t;
	
	while(t--){
		ull n, m;
		cin >> n >> m;
		
		ull data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		ull sum = 0, a = 0, b = 0;

		for(int x=0;x<n;x++){
			sum += (data[x]+m-1)/m;
			
			if(data[x]%m != 0) b += data[x];
			else a += data[x];
		}

		cout << a/m+(b+m-1)/m << " " << sum << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

