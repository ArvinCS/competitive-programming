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
	
	int ans = 0, cnt = 1;
	
	for(int x=1;x<s.length();x++){
		if(s[x] != s[x-1]){
			cnt++;
		} else {
			ans = max(ans, cnt);
			cnt = 1;
		}
	}
	
	cout << max(ans, cnt) << "\n";
    return 0;
}

