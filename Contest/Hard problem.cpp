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

string rev(string s){
	string ans = s;
	
	for(int x=0;x<s.length()/2;x++){
		swap(ans[x], ans[s.length()-x-1]);
	}
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll c[n];
	for(int x=0;x<n;x++){
		cin >> c[x];
	}
	
	string s[n];
	for(int x=0;x<n;x++) cin >> s[x];
	
	ull table[n+1][2];
	fill(table[0], table[n+1], inf_ll);
	
	table[1][0] = 0;
	table[1][1] = c[0];
	for(int x=1;x<n;x++){
		table[x+1][0] = min((s[x] >= rev(s[x-1]) ? table[x][1] : inf_ll), (s[x] >= s[x-1] ? table[x][0] : inf_ll));
		table[x+1][1] = min((rev(s[x]) >= rev(s[x-1]) ? table[x][1] + c[x] : inf_ll), (rev(s[x]) >= s[x-1] ? table[x][0] + c[x] : inf_ll));
	}
	
	if(min(table[n][0], table[n][1]) >= inf_ll){
		cout << "-1\n";
		return 0;
	}
	
	cout << min(table[n][0], table[n][1]) << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

