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

const int maxN = 505;
const int maxA = 1600;

int table[maxN][maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	fill(table[0], table[maxN], -1);
	for(int x=0;x<n;x++){
		table[x][x] = a[x];
	}
	
	for(int r=0;r<n;r++){
		for(int l=r-1;l>=0;l--){
			for(int m=l;m<r;m++){
				if(table[l][m] != -1 && table[l][m] == table[m+1][r]){
					table[l][r] = table[l][m]+1;
				}
			}
		}
	}
	
	int ans[n+1];
	ans[0] = 0;
	for(int x=1;x<=n;x++){
		ans[x] = inf_int;
		for(int y=0;y<x;y++){
			if(table[y][x-1] != -1){
				ans[x] = min(ans[x], ans[y]+1);
			}
		}
	}
	
	cout << ans[n] << "\n";
    return 0;
}

