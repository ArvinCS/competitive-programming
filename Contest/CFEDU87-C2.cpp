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
	
	double pi = atan(1)*4;
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		double ans = 1.0 / (2 * sin(pi/(4*n)));
		
		cout << fixed << setprecision(7) << ans << "\n";
	}

    return 0;
}

