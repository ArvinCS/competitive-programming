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
	
	us t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(x == 0){
					if(y % 2 == 0) cout << "1";
					else cout << "0";
				} else if(x-1 > 0 && x == n-1){
					if(y % 2 == 0) cout << "1";
					else cout << "0";
				} else if(x % 2 == 0){
					if(y == 0 || (y == m-1 && y-1 > 0)){
						if(x+1 != n-1){
							cout << "1";
						} else {
							cout << "0";
						}
					} else {
						cout << "0";
					}
				} else {
					cout << "0";
				}
			}
			cout << "\n";
		}
		cout << "\n";
	}
	
    return 0;
}

