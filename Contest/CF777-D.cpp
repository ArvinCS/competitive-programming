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
		ll n, d;
		cin >> n >> d;
		
		ll cur = n;
		int cnt = 0;
		while(cur % d == 0){
			cur /= d;
			cnt++;
		}
		
		if(cnt < 2){
			cout << "NO\n";
			continue;
		}
		
		n /= d*d;
		
		int ans = 0;
		for(int x=1;x*x<=n;x++){
			if(n%x == 0){
				if(x % d != 0 || (n/x) % d != 0) ans++;
			}
		}
		
		if(ans >= 2){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

