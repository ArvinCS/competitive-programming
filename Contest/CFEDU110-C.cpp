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
	
	while(t--){
		string s;
		cin >> s;
		
		int n = s.length();
		int prefix[n][2]; // 0 1
		for(int x=0;x<n;x++){
			for(int y=0;y<2;y++) prefix[x][y] = (x > 0 ? prefix[x-1][y] : 0);
			if(s[x] == '?'){
				prefix[x][0]++;
				prefix[x][1]++;
				continue;
			}
			
			if(x % 2 == 0 && s[x] == '0'){
				prefix[x][0]++;
			} else if(x % 2 == 1 && s[x] == '1'){
				prefix[x][0]++;
			}
			
			if(x % 2 == 0 && s[x] == '1'){
				prefix[x][1]++;
			} else if(x % 2 == 1 && s[x] == '0'){
				prefix[x][1]++;
			}
		}
		
		ll ans = 0;
		for(int x=0;x<n;x++){
			int left = 0, right = x, pos = x;
			while(left <= right){
				int mid = (left+right) >> 1;
				
				int length = x-mid+1;
				int zero = (prefix[x][0] - (mid > 0 ? prefix[mid-1][0] : 0));
				int one = (prefix[x][1] - (mid > 0 ? prefix[mid-1][1] : 0));
				
//				cout << mid << " " << zero << " " << one << "\n";
				if(zero == length || one == length){
					pos = mid;
					right = mid-1;
				} else {
					left = mid+1;
				}
			}
			
			ans += (x-pos+1);
//			cout << x << ": " << ans << "(" << pos << ")\n";
		}
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

