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
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		ll ans = 0;
		int one = -1, zero = -1;
		for(int x=0;x<n;x++){
			if(s[x] == '0'){
				if(x > 0 && s[x-1] == '1'){
					ans += x+1;
				} else {
					ans++;
				}
//				ans += (x-zero);
				zero = x;
			} else {
				if(x > 0 && s[x-1] == '0'){
					ans += x+1;
				} else {
					ans++;
				}
//				ans += x+1;
				one = x;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

