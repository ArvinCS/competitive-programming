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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		int c, d;
		cin >> c >> d;
		
		if(abs(c-d) % 2 == 1){
			cout << "-1\n";
		} else if(c == 0 && d == 0){
			cout << 0 << "\n";
		} else if(c == d){
			cout << 1 << "\n";
		} else {
			cout << 2 << "\n";
		}
	}

    return 0;
}

