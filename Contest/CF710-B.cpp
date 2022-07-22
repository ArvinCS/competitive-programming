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
		int n,k;
		cin >> n >> k;
		
		string s;
		cin >> s;
		
		int ans = 0, start = -1, last = -1;
		for(int x=0;x<n;x++){
			if(s[x] == '*'){
				s[x] = 'x';
				ans++;
				start = x;
				break;
			}
		}
		for(int x=n-1;x>=0;x--){
			if(s[x] == '*'){
				s[x] = 'x';
				ans++;
				last = x;
				break;
			}
		}
		
		if(last == -1 || last-start <= k){
			cout << ans << "\n";
			continue;
		}
		
		int idx = start+k;
		while(idx < last){
			for(int x=0;x<k;x++){
				if(s[idx-x] == '*'){
					s[x] = 'x';
					ans++;
					idx = idx-x;
					break;
				}
			}
			idx += k;
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

