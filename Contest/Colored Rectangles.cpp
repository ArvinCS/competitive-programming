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
	
	us rcnt, gcnt, bcnt;
	cin >> rcnt >> gcnt >> bcnt;
	
	int r[rcnt], g[gcnt], b[bcnt];
	
	for(us x=0;x<rcnt;x++) cin >> r[x];
    for(us x=0;x<gcnt;x++) cin >> g[x];
    for(us x=0;x<bcnt;x++) cin >> b[x];
    
    sort(r, r+rcnt, greater<int>());
    sort(g, g+gcnt, greater<int>());
    sort(b, b+bcnt, greater<int>());
	
	ull table[rcnt+1][gcnt+1][bcnt+1], best = 0;
	fill(&table[0][0][0], &table[0][0][0] + (rcnt+1)*(gcnt+1)*(bcnt+1), 0);
	
	for(int i=0;i<=rcnt;i++){
		for(int j=0;j<=gcnt;j++){
			for(int k=0;k<=bcnt;k++){
				if(i < rcnt && j < gcnt) table[i+1][j+1][k] = max(table[i+1][j+1][k], table[i][j][k] + r[i] * g[j]);
				if(i < rcnt && k < bcnt) table[i+1][j][k+1] = max(table[i+1][j][k+1], table[i][j][k] + r[i] * b[k]);
				if(j < gcnt && k < bcnt) table[i][j+1][k+1] = max(table[i][j+1][k+1], table[i][j][k] + g[j] * b[k]);
				
				best = max(best, table[i][j][k]);
			}
		}
	}
		
	cout << best << "\n";	
	return 0;
}

