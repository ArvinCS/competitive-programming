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
	
	short t;
	cin >> t;
	
	while(t--){
		short n;
		cin >> n;
		
		string s;
		cin >> s;
		
		char data[] = {'2', '0', '2', '0'};
		int cur = 0;
		
		for(int x=0;x<n;x++){
			if(s[x] != data[cur]) break;
			cur++;
		}
		
		for(int x=n+cur-4;x<n;x++){
			if(s[x] != data[cur]) break;
			cur++;
		}
		
		if(cur >= 4) cout << "YES\n";
		else cout << "NO\n";
	}
	
    return 0;
}

