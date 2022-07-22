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
	
	int h, w;
	cin >> h >> w;
	
	int total = 0, lowest = inf_int;
	for(int x=0;x<h;x++){
		for(int y=0;y<w;y++){
			int tmp;
			cin >> tmp;
			
			total += tmp;
			lowest = min(lowest, tmp);
		}
	}
	
	cout << total-(lowest*w*h) << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

