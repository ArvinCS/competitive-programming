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
		
		if(n > 2 && m == 1){
			cout << "-1\n";
			continue;
		}
		if(n == 1 && m > 2){
			cout << "-1\n";
			continue;
		}
		
		ll val = 0;
		if(n > m){
			val = max(0ll, n-m);
			if((n-m)&1){
				val = max(0ll, val-1);
			}
		} else {
			val = max(0ll, m-n);
			if((m-n)&1){
				val = max(0ll, val-1);
			}
		}
		
		cout << (n+m-2)+val << "\n";
	}
	
    return 0;
}

