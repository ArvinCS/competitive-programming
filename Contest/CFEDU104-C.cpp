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
		int n;
		cin >> n;
		
		if(n == 2){
			cout << "0\n";
		} else if(n == 3){
			cout << "-1 1 -1\n";
		} else {
			for(int x=1;x<=n-1;x++){
				for(int y=x+1;y<=n;y++){
					if(!(x == 1 && y == 2)) cout << " ";
					
					int tmp = y-x;
					if(2*tmp < n) cout << "1";
					else if(2*tmp == n) cout << "0";
					else cout << "-1";
				}
			}
			cout << "\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

