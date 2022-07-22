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
		
		int data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		int ans = 0;
		for(int x=0;x<n-1;x++){
			int low = min(data[x], data[x+1]);
			int tmp = (max(data[x], data[x+1])+low-1)/ low;
			if(tmp > 2){
				int cur = low;
				while((max(data[x], data[x+1])+cur-1) / cur > 2){
					cur *= 2;
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

