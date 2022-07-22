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
	
	string s;
	cin >> s;
	
	map<char, int> mp;
	mp['c'] = 0;
	mp['h'] = 1;
	mp['o'] = 2;
	mp['k'] = 3;
	mp['u'] = 4;
	mp['d'] = 5;
	mp['a'] = 6;
	mp['i'] = 7;
	
	ll cnt[8];
	fill(cnt, cnt+8, 0);
	
	for(int x=0;x<s.length();x++){
		if(mp.find(s[x]) != mp.end()){
			if(mp[s[x]] != 0){
				cnt[mp[s[x]]] += cnt[mp[s[x]]-1];
			} else {
				cnt[mp[s[x]]]++;
			}
			cnt[mp[s[x]]] %= mod;
		}	
	}
	
	cout << cnt[7] << "\n";
    return 0;
}

