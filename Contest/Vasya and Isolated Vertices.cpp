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
	
	long long n, m;
	cin >> n >> m;
	
	long long mx = 0;
	if(m > 0){
		while(mx*(mx-1)/2 < m){
			mx++;
		}
	}
	
	cout << n-min(n,m*2) << " " << n-mx << "\n";
    return 0;
}

