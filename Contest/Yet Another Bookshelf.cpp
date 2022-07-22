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
		
		short data[n], last[n], lastPos = -1, cnt = 0;
		for(short x=0;x<n;x++){
			cin >> data[x];
			
			last[x] = lastPos;
			if(data[x] == 1){
				cnt++;
				lastPos = x;
			}
		}
		
		if(cnt > 1){
			int ans = 0;
			for(short x=n-1;x>=1;x--){
				if(data[x-1] == 0 && data[x] == 1){
					if(last[x] != -1) ans += x-last[x]-1;
				}
			}
			cout << ans << "\n";
		} else {
			cout << "0\n";
		}
		
	}
	
    return 0;
}

