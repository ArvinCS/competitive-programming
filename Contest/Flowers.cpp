#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007

int table[100001][100001];

int dp(int start, int end, int k, bool useW, bool valid){
	if(start > end) return 0;
	if(start == end){
		return 1;
	}
	if(table[start][end] < mod) return table[start][end];
	
	int best = !useW ? dp(start+k, end, k, true, true) : 0;
	
	for(int x=start+1;x<=end;x++){
		best += dp(x,end,k,false,valid);
		best %= mod;
	}
	
	return table[start][end] = best % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fill(table[0], table[100001], mod);
	
	int t, k;
	cin >> t >> k;
	
//	dp(1,100000,k,false,false);
	
	while(t--){
		int a, b;
		cin >> a >> b;
		
		cout << dp(a, b, k, false, false) << "\n";
	}
	
    return 0;
}

