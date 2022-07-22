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
	
	string s;
	cin >> s;
	
	bool weak = true;
	for(int x=1;x<4;x++){
		if(s[x] != s[0]){
			weak = false;
			break;
		}
	}
	
	if(!weak){
		weak = true;
		for(int x=1;x<4;x++){
			if(((s[x-1] - '0')+1) % 10 != (s[x] - '0')){
				weak = false;
				break;
			}
		}
	}
	
	if(weak) cout << "Weak\n";
	else cout << "Strong\n";
    return 0;
}

