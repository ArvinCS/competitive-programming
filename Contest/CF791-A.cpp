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
		ll n;
		cin >> n;
		
		ll mn = 1e18, mx = 0;
		for(int x=0;x<=3;x++){
			if(n >= x*4 && (n-x*4) % 6 == 0){
				mn = min(mn, (n-x*4)/6 + x);
				mx = max(mx, (n-x*4)/6 + x);
			}
			if(n >= x*6 && (n-x*6) % 4 == 0){
				mn = min(mn, (n-x*6)/4 + x);
				mx = max(mx, (n-x*6)/4 + x);
			}
		}
		
		if(mx == 0){
			cout << "-1\n";
			continue;
		}
		
		cout << mn << " " << mx << "\n";
	}
	
    return 0;
}

