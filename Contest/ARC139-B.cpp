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
		ll n, a, b, x, y, z;
		cin >> n >> a >> b >> x >> y >> z;
		
		if(a > b){
			swap(a, b);
			swap(y, z);
		}
		if(y > x*a){
			y = x*a;
		}
		if(z > x*b){
			z = x*b;
		}
		if(b%a == 0 && z > y*(b/a)){
			z = y*(b/a);
		}
		if(a*z > b*y){
			swap(a, b);
			swap(y, z);
		}
		
		ll lcm = (a*b)/__gcd(a, b);
		ll mnA = lcm/a, mnB = lcm/b;
		
		for(int )
	}
	
    return 0;
}

