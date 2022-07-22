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
	
	int n;
	cin >> n;
	
	int minX = inf_int, minY = inf_int;
	int maxX = -inf_int, maxY = -inf_int;
	while(n--){
		int x, y;
		cin >> x >> y;
		
		minX = min(minX, x);
		maxX = max(maxX, x);
		minY = min(minY, y);
		maxY = max(maxY, y);
	}
	
	cout << (maxX-minX+1)/2 << " " << (maxY-minY+1)/2 << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

