#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		ll n, m;
		cin >> n >> m;
		
		if(n % 2 == 0){
			ll odd = (m+1)/2;
			ll even = m/2;
			
			cout << n-(odd*(odd-1) + odd)+(even*(even+1)) << "\n";
		} else {
			ll odd = (m+1)/2;
			ll even = m/2;
			
			cout << n+(odd*(odd-1) + odd)-(even*(even+1)) << "\n";
		}
	}
	
    return 0;
}

