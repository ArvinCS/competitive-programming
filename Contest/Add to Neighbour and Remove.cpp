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
		short n;
		cin >> n;
		
		int data[n];
		for(short x=0;x<n;x++) cin >> data[x];
		
		int prefix[n];
		prefix[0] = data[0];
		for(short x=1;x<n;x++){
			prefix[x] = data[x] + prefix[x-1];
		}
		
		int ans = inf_int;
		for(short x=0;x<n;x++){
			int val = prefix[x], cnt = x;
			short last = x, index = x+1;
			
			while(index < n){
				if(prefix[index] - prefix[last] == val){
					cnt += index-last-1;
					last = index;
				}
				index++;
			}
			
			if(last == n-1){
				ans = min(ans, cnt);
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

