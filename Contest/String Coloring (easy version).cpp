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
	
	short ans[n];
	fill(ans, ans+n, -1);
	
	vector<char> v1, v2;
	for(int x=0;x<n;x++){
		if(v1.size() == 0 || v1.back() <= s[x]){
			ans[x] = 0;
			v1.push_back(s[x]);
		} else if(v2.size() == 0 || v2.back() <= s[x]){
			ans[x] = 1;
			v2.push_back(s[x]);
		} else {
			cout << "NO\n";
			return 0;
		}
	}
	
	cout << "Yes\n";
	for(int x=0;x<n;x++){
		cout << ans[x];
	}
	cout << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

