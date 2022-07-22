#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

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
		if(a == b+c){
			possible = true;
		}
		if(b == a+c){
			possible = true;
		}
		if(c == a+b){
			possible = true;
		}
		if(a % 2 == 0 && b == c){
			possible = true;
		}
		if(b % 2 == 0 && a == c){
			possible = true;
		}
		if(c % 2 == 0 && a == b){
			possible = true;
		}
		
		cout << (possible ? "YES" : "NO") << "\n";
	}
	
    return 0;
}
