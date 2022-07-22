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
	
	string s, t;
	cin >> s >> t;
	
	if(s == t){
		cout << "Yes\n";
		return 0;
	}
	
	for(int x=0;x+1<s.length();x++){
		swap(s[x], s[x+1]);
		
		if(s == t){
			cout << "Yes\n";
			return 0;
		}
		
		swap(s[x], s[x+1]);
	}
	
	cout << "No\n";
    return 0;
}

