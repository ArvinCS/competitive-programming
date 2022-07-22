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
	
	short n;
	string s;
	cin >> n >> s;
	
	int cnt[n][4]; // 1 A | 2 T | 3 C | 4 G
	fill(cnt[0], cnt[n], 0);
	
	for(short x=0;x<n;x++){
		if(x > 0){
			cnt[x][0] = cnt[x-1][0];
			cnt[x][1] = cnt[x-1][1];
			cnt[x][2] = cnt[x-1][2];
			cnt[x][3] = cnt[x-1][3];
		}
		if(s[x] == 'A'){
			cnt[x][0]++;
		} else if(s[x] == 'T'){
			cnt[x][1]++;
		} else if(s[x] == 'C'){
			cnt[x][2]++;
		} else {
			cnt[x][3]++;
		}
	}
	
	ll ans = 0;
	for(short x=0;x<n;x++){
		for(short y=x;y<n;y++){
			int cntA = cnt[y][0] - (x > 0 ? cnt[x-1][0] : 0);
			int cntT = cnt[y][1] - (x > 0 ? cnt[x-1][1] : 0);
			int cntC = cnt[y][2] - (x > 0 ? cnt[x-1][2] : 0);
			int cntG = cnt[y][3] - (x > 0 ? cnt[x-1][3] : 0);
			if(cntA == cntT && cntC == cntG){
				ans++;
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

