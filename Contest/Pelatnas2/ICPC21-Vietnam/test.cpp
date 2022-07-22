#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll a, b;
	cin >> a >> b;
	
	
	ll last_a = a, last_b = b;
	ll div = a*b;
	for(int x=1;x<=30;x++){
		if((a+b) % div == 0){
			cout << a << " " << b << " " << x << " -\n";
			break;
		}
		
		a *= last_a;
		b *= last_b;
	}
	return 0;
}
