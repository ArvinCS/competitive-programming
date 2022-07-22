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
		int n, k;
		cin >> n >> k;
		
		ll data[n];
		for(int x=0;x<n;x++) cin >> data[x];
		
		sort(data, data+n);
		
		ll maxAns = data[n-1], minAns = data[0];
		for(int x=n-k-1;x<n-1;x++){
			maxAns += data[x];
			data[x] = 0;
			minAns = min(data[x], minAns);
		}
		
		cout << abs(maxAns-minAns) << "\n";
	}
	
    return 0;
}

