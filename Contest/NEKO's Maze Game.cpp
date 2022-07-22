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

const int maxN = 1e5 + 5;

bool valid[3][maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	valid[1][0] = valid[2][0] = true;
	for(int x=1;x<=2;x++){
		for(int y=1;y<=n;y++){
			valid[x][y] = true;
		}
	}

	for(int i=0;i<m;i++){
		int a, b;
		cin >> a >> b;
		
		if(dsu[a][b] == -1){
			dsu[a][b] = b-1;
		} else {
			dsu[a][b] = -1;
		}
		
//		cout << getParrent(1, n) << " " << getParrent(2, n) << "\n";
		if(check(n)){
			cout << a << " " << b << " Yes\n";
		} else {
			cout << a << " " << b << " No\n";
		}
	}
	
    return 0;
}
// Santai
// Pikirin dengan benar-benar

