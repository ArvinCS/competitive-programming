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
		
		int ans = 2, i = 0;
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				if(y > 0) cout << " ";
				if(i == y || (i+1)%n == y){
					cout << "1";
				} else {
					cout << "0";
				}
			}
			i++;
			cout << "\n";
		}
	}
	
    return 0;
}

