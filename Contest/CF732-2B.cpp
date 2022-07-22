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
		int n, m;
		cin >> n >> m;
		
		int cnt[m][26][2]; // 0 before 1 after
		fill(*cnt[0], *cnt[m], 0);
		
		string s[n];
		for(int x=0;x<n;x++){
			cin >> s[x];
			
			for(int y=0;y<s[x].length();y++){
				cnt[y][(s[x][y] - 'a')][0]++;
			}
		}
		
		for(int x=0;x<n-1;x++){
			string tmp;
			cin >> tmp;
			
			for(int y=0;y<tmp.length();y++){
				cnt[y][(tmp[y] - 'a')][1]++;
			}
		}
		
		string ans;
		for(int x=0;x<m;x++){
			for(int y=0;y<26;y++){
				if((cnt[x][y][0] - cnt[x][y][1]) != 0){
					char c = ('a' + y);
					ans += c;
					break;
				}
			}
		}
		
		cout << ans << endl;
	}
	
    return 0;
}

