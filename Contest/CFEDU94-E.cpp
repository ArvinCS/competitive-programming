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

const int maxN = 5005;
const int lgN = log2(maxN);

int n, a[maxN];
pair<int, int> table[lgN+1][maxN];

void build(){
	for(int x=0;x<n;x++){
		table[0][x] = {a[x], x};
	}
	for(int x=1;x<=lgN;x++){
		int length = (1 << x);
		for(int y=0;y+length<=n;y++){
			table[x][y] = min(table[x-1][y], table[x-1][y+length/2]);
		}
	}	
}

pair<int, int> rmq(int left, int right){
	int lg = log2(right-left+1);
	int length = (1 << lg);
	
	return min(table[lg][left], table[lg][right-length+1]);
}

int solve(int left, int right, int val){
	if(left > right) return 0;
	
	pair<int, int> mn = rmq(left, right);
	
	if(mn.first == val){
		return solve(left, mn.second-1, val) + solve(mn.second+1, right, val);
	} else {
		return min(right-left+1, mn.first-val + solve(left, mn.second-1, mn.first) + solve(mn.second+1, right, mn.first));
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	build();
	
	cout << solve(0, n-1, 0) << "\n";
	
    return 0;
}

