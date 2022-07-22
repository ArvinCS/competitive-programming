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

	int h, w, a, b;
	cin >> h >> w >> a >> b;
	
	char data[h+1][w+1];
	for(int x=1;x<=h;x++){
		for(int y=1;y<=w;y++) cin >> data[x][y];
	}
	
	int ans = 1;
	for(int x=a-1;x>=1;x--){
		if(data[x][b] == '#') break;
		ans++;
	}
	for(int x=a+1;x<=h;x++){
		if(data[x][b] == '#') break;
		ans++;
	}
	for(int x=b-1;x>=1;x--){
		if(data[a][x] == '#') break;
		ans++;
	}
	for(int x=b+1;x<=w;x++){
		if(data[a][x] == '#') break;
		ans++;
	}
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

