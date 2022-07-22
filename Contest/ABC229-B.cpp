#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	ll a, b;
	cin >> a >> b;
	
	bool hard = false;
	while(a > 0 && b > 0){
		if((a%10) + (b%10) >= 10){
			hard = true;
			break;
		}
		
		a /= 10;
		b /= 10;
	}
	
	if(hard){
		cout << "Hard\n";
	} else {
		cout << "Easy\n";
	}
    return 0;
}

