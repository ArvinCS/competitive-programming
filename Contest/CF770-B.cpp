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
		ll n, x, y;
		cin >> n >> x >> y;
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		int odd = 0;
		for(int x=0;x<n;x++){
			if(a[x]&1) odd++;
		}
		
		odd %= 2;
		
		if((x&1)^odd == (y&1)){
			cout << "Alice\n";
		} else {
			cout << "Bob\n";
		}
	}
	
    return 0;
}

