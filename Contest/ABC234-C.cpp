#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll k;
	cin >> k;
	
	bool zero = false;
	for(int x=60;x>=0;x--){
		ll bit = (1ll << x);
		
		if(k&bit){
			zero = true;
			if(zero) cout << "2";
		} else {
			if(zero) cout << "0";
		}
	}
	cout << "\n";
    return 0;
}

