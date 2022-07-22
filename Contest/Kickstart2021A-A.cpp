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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		int n, k;
		cin >> n >> k;
		
		string s;
		cin >> s;
		
		int score = 0, left = 0;
		for(int x=0;x<n/2;x++){
			if(s[x] != s[n-1-x]){
				score++;
			}
		}
		
		int ans = 0;
		if(score <= k){
			ans = k-score;
		} else {
			ans = score-k;
		}
		cout << "Case #" << i << ": " << ans << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

