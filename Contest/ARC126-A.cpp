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
		ll a, b, c;
		cin >> a >> b >> c;
		
		b /= 2;
		
		swap(b, c);
		
		ll ans = 0;
		ll mn = min(b, c);
		
		ans += mn;
		b -= mn; c -= mn;
		
		if(b == 0){
			mn = min(a/2, c);
			
			ans += mn;
			a -= mn*2; c -= mn;
		} else {
			mn = min(a, b/2);
			
			ans += mn;
			a -= mn; b -= mn * 2;
			
			if(a >= 3 && b >= 1){
				ans++;
				a -= 3;
				b--;
			}
		}
		
		ans += a/5;
		cout << ans << "\n";
	}

    return 0;
}

