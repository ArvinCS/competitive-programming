#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll v, a, b, c;
	cin >> v >> a >> b >> c;
	
	v %= (a+b+c);
	
	if(v < a){
		cout << "F\n";
	} else if(v < a+b){
		cout << "M\n";
	} else {
		cout << "T\n";
	}
	
    return 0;
}

