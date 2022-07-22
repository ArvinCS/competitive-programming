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
	
	for(int i=1;i<=t;i++){
		int n, p;
		cin >> n >> p;
		
		int data[n];
		for(int x=0;x<n;x++) cin >> data[x];
		
		sort(data, data+n);
		
		int best = 0, tmp = 0;
		for(int x=0;x<p;x++){
			tmp += data[x];
		}
		best = data[p-1]*p-tmp;
		
		for(int x=p;x<n;x++){
			tmp -= data[x-p];
			tmp += data[x];
			best = min(best, data[x]*p-tmp);
		}
		
		cout << "Case #" << i << ": " << best << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

