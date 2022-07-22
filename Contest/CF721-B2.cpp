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

const int maxN = 1e3 + 5;

int table[maxN][maxN][2][2][2];

int dp(int same, int need, int mid, bool rev, bool bob){
	if(same+need+(mid^1) == 0){
		return 0;
	}
	if(table[same][need][mid][rev][bob] != -inf_int) return table[same][need][mid][rev][bob];
	
	int ans = (bob ? -inf_int : inf_int);
	if(!rev && need != 0){
		if(bob){
			ans = max(ans, dp(same, need, mid, true, bob^1));
		} else {
			ans = min(ans, dp(same, need, mid, true, bob^1));
		}
	}
	
	if(need > 0){
		if(bob){
			ans = max(ans, dp(same, need-1, mid, false, bob^1)-1);
		} else {
			ans = min(ans, dp(same, need-1, mid, false, bob^1)+1);
		}
	}
	if(same > 0){
		if(bob){
			ans = max(ans, dp(same-1, need+1, mid, false, bob^1)-1);
		} else {
			ans = min(ans, dp(same-1, need+1, mid, false, bob^1)+1);
		}
	}
	if(mid == 0){
		if(bob){
			ans = max(ans, dp(same, need, 1, false, bob^1)-1);
		} else {
			ans = min(ans, dp(same, need, 1, false, bob^1)+1);
		}
	}
	return table[same][need][mid][rev][bob] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	fill(***table[0], ***table[maxN], -inf_int);
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		int mid = 1, same = 0, need = 0;
		for(int x=0;x<n/2;x++){
			if(s[x] == s[n-1-x] && s[x] == '0'){
				same++;
			}
			if(s[x] != s[n-1-x]){
				need++;
			}
		}
		
		if(n % 2 == 1 && s[n/2] == '0'){
			mid = 0;
		}
		
		int ans = dp(same, need, mid, false, false);
		if(ans > 0){
			cout << "BOB\n";
		} else if(ans == 0){
			cout << "DRAW\n";
		} else {
			cout << "ALICE\n";
		}
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

