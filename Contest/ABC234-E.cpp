#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n;
	cin >> n;
	
	ll ans = 1e18;
	for(int l=1;l<=18;l++){
		for(int f=1;f<=9;f++){
			for(int d=-9;d<=9;d++){
				if(f+(l-1)*d >= 0 && f+(l-1)*d <= 9){
					ll val = 0, cur = f;
					
					for(int x=1;x<=l;x++){
						val *= 10;
						val += cur;
						
						cur += d; 
					}
					
					if(val >= n) ans = min(ans, val);
				}
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

