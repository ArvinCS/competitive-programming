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

	int n, m;
	cin >> n >> m;
	
	char label[n+1][n+1];
	fill(label[0], label[n+1], '.');
	
	for(int x=0;x<m;x++){
		int a, b;
		char c;
		cin >> a >> b >> c;
		
		label[a][b] = c;
		label[b][a] = c;	
	}
	
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

