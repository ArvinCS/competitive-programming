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
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;

		if(a == c && a == e && min(b,d) <= f && f <= max(b,d)){
			cout << abs(b-d)+2 << "\n";
		} else if(b == d && b == f && min(a,c) <= e && e <= max(a,c)){
			cout << abs(a-c)+2 << "\n";
		} else {
			cout << abs(a-c)+abs(b-d) << "\n";
		}
	}

    return 0;
}

