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
		ll k;
		cin >> k;
		
		vector<pair<ll, ll>> v;
		for(int x=2;k>0;x++){
			v.push_back({k%x, x});
			k /= x;
		}
		
		// revese the ops:
		// (((Pn-1 + Rn-1) * Pn-2 + Rn-2) * Pn-3 + Rn-3) * .... ) * P1 + R1)
		// (Pn-1 + Rn-1) * (Pn-2 * Pn-3 * ... * P1) + Rn-2 * (Pn-3 * ... * P1) + R1
		// Mul P1*..*Pn + Rn-1 * (Pn-2 * Pn-3 * ... * P1) + Rn-2 * (Pn-3 * ... * P1) + R1
		// find ways to rearrange R with different result 
		
		for(auto p : v){
			cout << p.first << " " << p.second << "\n";
		}
		cout << " -----\n";
		
		// 4*(2*3*4) + 2*(5*4*3*2) + 3*(6*5*4*3*2) + 0 + 3*(8*7*6*5*4*3*2)
		// 2*(5*4*3*2) + 3*(6*5*4*3*2) + 3*(7*6*5*4*3*2) + 4*(8*7*6*5*4*3*2)
	}
	
    return 0;
}

