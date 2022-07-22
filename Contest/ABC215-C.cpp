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

vector<string> v;
string s;

void solve(int idx){
	if(idx >= s.length()){
		v.push_back(s);
		return;
	}
	
	for(int x=idx;x<s.length();x++){
		swap(s[idx], s[x]);
		solve(idx+1);
		swap(s[idx], s[x]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	cin >> s;
	
	int k;
	cin >> k;
	
	solve(0);
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	cout << v[k-1] << "\n";
	
    return 0;
}

