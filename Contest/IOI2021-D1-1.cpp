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

int[] distribute_candies(int[] c, int[] l, int[] r, int[] v){
	
}

int main(){
	int n;
	cin >> n;
	
	int c[n];
	for(int x=0;x<n;x++){
		cin >> c[x];
	}
	
	int l[q], r[q], v[q];
	for(int x=0;x<q;x++){
		cin >> l[x] >> r[x] >> v[x];
	}
	
	int ans[q] = distribute_candies(c, l, r, v);
	for(int x=0;x<q;x++){
		cout << ans[x] << "\n";
	}
}

