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
	
	int n[3];
	cin >> n[0] >> n[1] >> n[2];
	
	int maxN = max(max(n[0], n[1]), n[3]);
	ll a[n[0]], b[n[1]], c[n[2]];
	for(int x=0;x<n[0];x++){
		cin >> a[x];
	}
	for(int x=0;x<n[1];x++){
		cin >> b[x];
	}
	for(int x=0;x<n[2];x++){
		cin >> c[x];
	}
	
	sort(a, a+n[0]);
	sort(b, b+n[1]);
	sort(c, c+n[2]);
	
	ll prefix[3][maxN];
	prefix[0][0] = a[0];
	prefix[1][0] = b[0];
	prefix[2][0] = c[0];
	
	for(int x=1;x<n[0];x++){
		prefix[0][x] = prefix[0][x-1] + a[x];
	} 
	for(int x=1;x<n[1];x++){
		prefix[1][x] = prefix[1][x-1] + b[x];
	}
	for(int x=1;x<n[2];x++){
		prefix[2][x] = prefix[2][x-1] + c[x];
	}
	
	ll ans = -inf_int;
	
	for(int x=0;x<3;x++){
		ll curX = prefix[x][n[x]-1]-(n[x] > 1 ? prefix[x][n[x]-2] : 0);
		ll leftX = prefix[x][n[x]-1]-curX;
		
		int next1 = (x+1)%3, next2 = (x+2)%3;
		ans = max(ans, curX-(curX+prefix[next1][n[next1]-1]+prefix[next2][n[next2]-1]));
	}
	
	cout << ans << "\n";
    return 0;
}
//
//int prev = (x+1)%3, next = (x+2)%3;
//ll tmp1 = prefix[x][0];
//if(next == y){
//	if(n[next] > 1) tmp1 -= prefix[next][n[next]-2];
//} else {
//	tmp1 -= prefix[next][n[next]-1];
//}
//if(prev == y){
//	if(n[prev] > 1) tmp1 -= prefix[prev][n[prev]-2];
//} else {
//	tmp1 -= prefix[prev][n[prev]-1];
//}
//ll tmp2 = prefix[y][n[y]-1]-(n[y] > 1 ? prefix[y][n[y]-2] : 0)-(n[x] > 1 ? prefix[x][n[x]-1] - prefix[x][0] : 0);
//cout << (n[x] > 1 ? prefix[x][n[x]-1] - prefix[x][0] : 0) << "\n";
//
//cout << x << " - " << y << " : " << tmp2-tmp1 << "(" << tmp1 << " , " << tmp2 << ")\n";
//ans = max(ans, tmp2-tmp1);
// Santai
// Pikirin dengan benar-benar

