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

const int maxN = 400005;

char grid[maxN];

int n;

char res(char a, char b){
	if(a == b) return a;
	
	if(a == 'W'){
		if(b == 'R'){
			return 'B';
		} else {
			return 'R';
		}
	} else if(a == 'R'){
		if(b == 'W'){
			return 'B';
		} else {
		 	return 'W';
		}
	} else { // B
		if(b == 'W'){
			return 'R';
		} else {
			return 'W';
		}
	}
}

char solve(int level, int idx){
	if(level == n){
		return grid[idx];
	}
	
	if(level+6 > n){
		if(level+3 > n){
			return res(solve(level+1, idx), solve(level+1, idx+1));
		}
		
		return res(solve(level+3, idx), solve(level+3, idx+3));
	}
	
	char tmp = solve(level+6, idx+3);
	return res(res(solve(level+6, idx), tmp), res(tmp, solve(level+6, idx+6)));
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> grid[x];
	}
	
	cout << solve(1, 0) << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

