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
	
	int a, b;
	cin >> a >> b;
	
	int ans1 = 0, ans2 = 0;
	while(a > 0){
		ans1 += (a % 10);
		a /= 10;	
	}
	while(b > 0){
		ans2 += (b % 10);
		b /= 10;	
	}
	
	cout << max(ans1, ans2) << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

