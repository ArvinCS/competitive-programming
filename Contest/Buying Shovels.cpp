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
		ui n, k;
		cin >> n >> k;
		
		if(k >= n){
			cout << "1 \n";
		} else {
			set<ull> divisors;
			for(ull x=1;x*1ll*x<=n;x++){
				if(n % x == 0){
					divisors.insert(x);
					if(n/x != x) divisors.insert(n/x);
				}
			}
			
			ull mx = 0;
			for(auto& a : divisors){
				if(a <= k && n % a == 0) mx = max(mx, a);
			}
			
			cout << n/mx << "\n";
		}
	}
	
    return 0;
}
