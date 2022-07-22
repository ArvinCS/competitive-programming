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
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		char ans[n][2];
		for(int x=0;x<n;x++){
			if(s[x] == 'U'){
				ans[x][0] = s[x];
				ans[x][1] = 'D';
			} else if(s[x] == 'R' || s[x] == 'L'){
				ans[x][0] = ans[x][1] = s[x];
			} else if(s[x] == 'D'){
				ans[x][0] = s[x];
				ans[x][1] = 'U';
			}
		}
		
		for(int x=0;x<n;x++){
			cout << ans[x][1];
		}
		cout << "\n";
	}
	
    return 0;
}

