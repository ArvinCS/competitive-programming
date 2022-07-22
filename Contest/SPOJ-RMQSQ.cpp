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
	
	int n, q;
	cin >> n;
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	int maxLog = log2(n);
	int table[maxLog][n];
	
	for(int x=0;x<=maxLog;x++){
		int length = 1 << x;
		for(int y=0;y+length-1<n;y++){
			if(length == 1){
				table[x][y] = data[y];
			} else {
				table[x][y] = min(table[x-1][y], table[x-1][y+length/2]);
			}
		}
	}
	
	cin >> q;
	
	for(int x=0;x<q;x++){
		int l, r;
		cin >> l >> r;
		
		int lg = log2(r-l+1);
		int length = 1 << lg;
		
		cout << min(table[lg][l], table[lg][r-length+1]) << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

