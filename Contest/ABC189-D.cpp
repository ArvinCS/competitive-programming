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
	
	bool a[n+1];
	for(int x=0;x<n;x++){
		string s;
		cin >> s;
		
		if(s == "AND"){
			a[x+1] = true;
		} else {
			a[x+1] = false;
		}
	}
	
	ll cnt[n+1][2];
	cnt[0][1] = cnt[0][0] = 1;
	
	for(int x=1;x<n+1;x++){
		if(a[x]){
			cnt[x][0] = 2 * cnt[x-1][0] + cnt[x-1][1]; // false
			cnt[x][1] = cnt[x-1][1];
		} else {
			cnt[x][0] = cnt[x-1][0]; // false
			cnt[x][1] = cnt[x-1][0] + 2 * cnt[x-1][1];
		}
	}
	
//	for(int x=0;x<2;x++){
//		for(int y=0;y<n+1;y++){
//			cout << cnt[y][x] << " ";
//		}
//		cout << "\n";
//	}
	cout << cnt[n][1] << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

