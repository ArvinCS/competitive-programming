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
	
	int n;
	cin >> n;
	
	string s, t;
	cin >> s >> t;
	
	string tmp = s;
	int one1 = 0, one2 = 0;
	for(int x=0;x<n;x++){
		if(s[x] == '1') one1++;
		if(t[x] == '1') one2++;
	}
	
	if(one1 != one2){
		cout << "-1\n";
		return 0;
	}
	
	vector<int> v, w;
	for(int x=0;x<n;x++){
		if(s[x] == '0') v.push_back(x);
		if(t[x] == '0') w.push_back(x);
	}
	
	int ans = 0;
	for(int x=0;x<v.size();x++){
		if(v[x] != w[x]) ans++;
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar
