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
		
		ll a = 0;
		for(int i=0;i<31;i++){
			if(n&(1ll << i)){
				a = (1ll << i);
				break;
			}
		}
		
		if(n == a){
			if(n == 1){
				cout << 3 << "\n";
			} else {
				cout << a+1 << "\n";
			}
		} else {
			cout << a << "\n";
		}
	}
	
    return 0;
}

