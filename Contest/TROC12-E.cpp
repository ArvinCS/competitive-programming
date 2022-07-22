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

	int t;
	cin >> t;
	
	while(t--){
		int x, y;
		cin >> x >> y;
		
		if(x == y || (x % 8 == 1 && y % 4 == 1)){
			cout << x+y+2 << "\n";
		} else {
			cout << x+y << "\n";
		}
	}

    return 0;
}

