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
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	for(int x=0;x<n;x++){
		if(s[x] == '1'){
			if(x%2 == 0) cout << "Takahashi\n";
			else cout << "Aoki\n";
			break;
		}
	}
	
    return 0;
}

