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
		
		int data[n], cnt[3];
		fill(cnt, cnt+3, 0);
		
		for(int x=0;x<n;x++){
			cin >> data[x];
			
			cnt[data[x]%3]++;
		}
		
		int ans = 0;
		int median = n/3;
		for(int x=0;x<3;x++){
			if(cnt[x] > median){
				int tmp = (cnt[x]-median);
				cnt[(x+1)%3] += tmp;
				cnt[x] -= tmp;
				ans += tmp;
			}
		}
		for(int x=0;x<3;x++){
			if(cnt[x] > median){
				int tmp = (cnt[x]-median);
				cnt[(x+1)%3] += tmp;
				cnt[x] -= tmp;
				ans += tmp;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

