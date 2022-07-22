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
		int a, b, c;
		cin >> a >> b >> c;
		
		bool possible = false;
		
		if((2*b - a) % c == 0 && (2*b - a)/c > 0){
			possible = true;
		}
		if((a+c) % (2*b) == 0 && (a+c)/(2*b) > 0){
			possible = true;
		}
		if((2*b - c) % a == 0 && (2*b - c)/a > 0){
			possible = true;
		}
		
		cout << (possible ? "YES" : "NO") << "\n";
	}
	
    return 0;
}

