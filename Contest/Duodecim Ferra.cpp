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
	
	ull table[1000][12];
	fill(table[0], table[1000], 0);
	
	for(int x=0;x<=n;x++) table[x][0] = 1;
	
	for(int i=0;i<11;i++){
		for(int t=i+1;t<=n;t++){
			for(int x=1;x<=n;x++){
				if(t+x > n) break;
				table[t+x][i+1] += table[t][i];
			}
		}
	}
//	
//	for(int i=0;i<12;i++){
//		for(int x=0;x<=n;x++){
//			cout << table[x][i] << " ";
//		}
//		cout << "\n";
//	}
	cout << table[n][11] << "\n";
    return 0;
}

