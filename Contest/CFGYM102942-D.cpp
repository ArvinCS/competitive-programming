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
		int a, b;
		cin >> a >> b;
		
		int score = a^b;
		bool valid = false;
		for(int x=1;x<=a;x++){
			int tmp = x^b;
			if(tmp > score){
				cout << "Yes\n";
				valid = true;
				break;
			}
		}
		if(!valid) cout << "No\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

