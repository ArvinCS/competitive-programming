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

	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		string s[3];
		cin >> s[0] >> s[1] >> s[2];
		
		int pos[3];
		pos[0] = pos[1] = pos[2] = 0;
		
		int last = -1;
		string ans;
		for(int x=0;x<3*n;x++){
			int zero = 0, one = 0;
			for(int i=0;i<3;i++){
				if(s[i][pos[i]] == '0') zero++;
				else one++;
			}
			
			if(zero >= one){
				ans.push_back('0');
				for(int i=0;i<3;i++){
					if(pos[i] < 2*n && s[i][pos[i]] == '0') pos[i]++;
				}
			} else {
				ans.push_back('1');
				for(int i=0;i<3;i++){
					if(pos[i] < 2*n && s[i][pos[i]] == '1') pos[i]++;
				}
			}
			
			for(int i=0;i<3;i++){
				if(pos[i] >= 2*n){
					last = i;
					break;
				}
			}
			if(last >= 0) break;
		}
		
		if(last >= 0){
			int nxt = (last+1) % 3, nxt2 = (last+2) % 3;
			if(pos[nxt] >= pos[nxt2]){
				while(pos[nxt] < 2*n && ans.length() < 3*n){
					ans.push_back(s[nxt][pos[nxt]]);
					pos[nxt]++;
				}
			} else {
				while(pos[nxt2] < 2*n && ans.length() < 3*n){
					ans.push_back(s[nxt2][pos[nxt2]]);
					pos[nxt2]++;
				}
			}
		}
		
		cout << ans << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar
