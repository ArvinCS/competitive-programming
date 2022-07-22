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

	int n, k;
	cin >> n >> k;
	
	int data[k];
	for(int x=0;x<k;x++) cin >> data[x];
	
	sort(data, data+k);
	
	int table[n+1][k+1];
	fill(table[0], table[n+1], 0);
	
	for(int x=0;x<=k;x++) table[0][x] = 1;
	for(int x=1;x<=n;x++){
		for(int y=1;y<=k;y++){
			int cnt = 0;
			for(int z=1;z*data[y-1]<=x;z++){
				cnt += table[x-z*data[y-1]][y-1];
			}
			table[x][y] = cnt;
		}
	}
	
	int ans = 0;
	for(int x=1;x<=k;x++) ans += table[n][x];
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

