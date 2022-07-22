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
	
	int n, m;
	cin >> n >> m;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	sort(a, a+n);
	
	int cnt = 0;
	for(int x=0;x<n;x++){
		cnt += (a[x] != a[(x+n/2)%n]);
	}

	cout << cnt << "\n";
	for(int x=0;x<n;x++){
		cout << a[x] << " " << a[(x+n/2)%n] << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar
