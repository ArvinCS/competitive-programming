#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n, m;
	cin >> n >> m;
	
	if(n < 2 || m < 2){
		cout << "-1\n";
		return 0;
	}
	
	if(n < m) swap(n, m);
	if(n % 2 == 0 && m % 2 == 0){
		cout << n*m/4 << "\n";
	} else {
		if(n % 2 == 0){ // m % 2 == 1
			cout << max(-1ll, (n/2)*(m-3)/2) << "\n";
		} else if(m % 2 == 0){
			cout << max(-1ll, (m/2)*(n-3)/2) << "\n";
		} else {
			bool valid = !(n <= 3 && m <= 3);
			for(int y=0;y<=1000;y++){
				if(n*m == 9) break;
				
				if(n*m-4*y >= 0 && (n*m-4*y) % 3 == 0){
					valid = true;
					break;
				}
			}
			
			if(valid){
				cout << "0\n";
			} else {
				cout << "-1\n";
			}
		}
	}
	
    return 0;
}

