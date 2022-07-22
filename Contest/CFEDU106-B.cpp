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
		
		int prefix[n], suffix[n+1];
		suffix[n] = inf_int;		
		int lastA = inf_int, lastB = -inf_int;
		
		for(int x=0;x<n;x++){
			prefix[x] = (x == 0 ? inf_int : prefix[x-1]);
			if(s[x] == '1'){
				prefix[x] = min(prefix[x], x-lastB);
				lastB = x;
			}
		}
		for(int x=n-1;x>=0;x--){
			suffix[x] = suffix[x+1];
			if(s[x] == '0'){
				suffix[x] = min(suffix[x], lastA-x);
				lastA = x;
			}
		}
		
//		for(int x=0;x<n;x++){
//			if(x > 0) cout << " ";
//			cout << prefix[x];
//		}
//		cout << "\n";
//		for(int x=0;x<n;x++){
//			if(x > 0) cout << " ";
//			cout << suffix[x];
//		}
//		cout << "\n";
		
		bool possible = false;
		if(suffix[0] > 1){
			possible = true;
		}
		for(int x=0;x<n;x++){
			if(s[x] == '0' && prefix[x] > 1 && suffix[x+1] > 1){
				possible = true;
				break;
			}
		}
		if(possible) cout << "YES\n";
		else cout << "NO\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

