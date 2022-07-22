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
		ll n, m, a, b;
		cin >> n >> m >> a >> b;
		
		// case 1 (n,m with 1,1)
		ll dist1 = min(abs(n-a) + abs(m-b) + abs(n-1) + abs(m-1), abs(a-1) + abs(b-1) + abs(n-1) + abs(m-1));
		// case 2 (n,1 with 1,m)
		ll dist2 = min(abs(n-a) + abs(1-b) + abs(1-n) + abs(m-1), abs(1-a) + abs(m-b) + abs(n-1) + abs(1-m));
		
		if(dist1 >= dist2){
			cout << n << " " << m << " " << 1 << " " << 1 << "\n";
		} else {
			cout << n << " " << 1 << " " << 1 << " " << m << "\n";
		}
	}
	
    return 0;
}

