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
		int n, a, b;
		cin >> n >> a >> b;
		
		int v, w;
		cin >> v >> w;
		
		int tmp1 = min(a,b), tmp2 = n-max(a,b);
		int diff = abs(a-b);
		
		tmp1 += diff/2;
		tmp2 += diff/2;
		
		if(v <= tmp1 && w <= tmp2){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

