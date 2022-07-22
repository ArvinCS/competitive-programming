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
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int w[n], cnt[n+1];
		fill(cnt, cnt+n+1, 0);
		
		for(int x=0;x<n;x++){
			cin >> w[x];
			cnt[w[x]]++;
		}
		
		int ans = 0;
		for(int s=2;s<=2*n;s++){
			int tmp = 0;
			for(int x=1;x<=(s+1)/2;x++){
				if(s-x > n) continue;
				tmp += min(cnt[x], cnt[s-x]);
			}
			if(s%)
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

