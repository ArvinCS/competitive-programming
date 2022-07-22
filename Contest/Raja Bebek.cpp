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

const int maxN = 1e4 + 5, maxY = 1e3 + 5;

int table[maxN][maxY], data[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, y;
	cin >> n >> y;
	
	for(int x=1;x<=n;x++){
		cin >> data[x];	
	}
	
	sort(data, data+n);
	fill(table[0], table[n+1], inf_int);
	
	for(int i=0;i<=n;i++){
		for(int w=0;w<=y;w++){
			if(i == 0 || w == 0){
				if(w == 0) table[i][w] = 0;
				else table[i][w] = inf_int;
			} else if(w-data[i] >= 0){
				table[i][w] = min(1 + table[i-1][w-data[i]], (i > 1 ? table[i-1][w] : n+1));
			} else {
				table[i][w] = table[i-1][w];
			}
		}
	}
//	
//	for(int x=0;x<=n;x++){
//		if(x > 0) cout << " ";
//		cout << table[x][y];
//	}
//	cout << "\n";
	cout << (table[n][y] > n ? -1 : table[n][y]) << "\n";
    return 0;
}

