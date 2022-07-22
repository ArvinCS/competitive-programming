#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

bool prime(int n){
	for(int i=2;i*i<=n;i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		if(n == 1){
			cout << "FastestFinger\n";
		} else if(n % 2 == 1 || (n-1) == 1){
			cout << "Ashishgup\n";
		} else {
			if((n & (n-1)) == 0 || (n % 4 != 0 && prime(n/2))){
				cout << "FastestFinger\n";
			} else {
				cout << "Ashishgup\n";
			}
		}
	}
	
    return 0;
}
