#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int lastDigit = (n+3)/4;
		for(int x=0;x<n-lastDigit;x++){
			cout << "9";
		}
		for(int x=0;x<lastDigit;x++){
			cout << "8";
		}
		cout << "\n";
	}
	
    return 0;
}

