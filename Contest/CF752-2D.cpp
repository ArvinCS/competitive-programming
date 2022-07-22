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
		ll a, b;
		cin >> a >> b;
		
		// xn + (n-a) = b
		// (x-1)n - a = b
		// (x-1)n = a+b
		
		if(a > b){
			cout << a+b << "\n";	
		} else if(a == b){
			cout << a << "\n";
		} else {
			if(b%a == 0){
				cout << a << "\n";
			} else {
				for(ll x=1;x*a<=b;x++){
					ll val = (x*a + b);
					bool found = false;
					for(ll y=2;y*y<=val;y++){
						if(val%y == 0){
							ll tmp = val/y;
							
							if((tmp%a) == (b%tmp)){
								cout << tmp << "\n";
								found = true;
								break;
							}
							
							if(val/y != y){
								tmp = val/(val/y);
								if((tmp%a) == (b%tmp)){
									cout << tmp << "\n";
									found = true;
									break;
								}
							}
						}
					}
					if(found) break;
				}
			}
		}
	}
	
    return 0;
}

