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
		
		string r, b;
		cin >> r >> b;
		
		int p1 = 0, p2 = 0;
		
		for(int x=0;x<n;x++){
			if(r[x] > b[x]) p1++;
			else if(r[x] < b[x]) p2++;
		}
		
		if(p1 > p2){
			cout << "RED\n";
		} else if(p1 < p2){
			cout << "BLUE\n";
		} else {
			cout << "EQUAL\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

