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
		
		bool possible = true;
		unordered_set<char> st;
		for(int x=0;x+1<n;x++){
			if(s[x] != s[x+1]){
				if(st.count(s[x])){
					possible = false;
					break;
				}
				if(st.count(s[x+1])){
					possible = false;
					break;
				}
				st.insert(s[x]);
			}
		}
		
		if(possible) cout << "YES\n";
		else cout << "NO\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

