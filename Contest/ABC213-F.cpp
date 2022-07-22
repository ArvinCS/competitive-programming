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
	
	int table[n];
	fill(table, table+n, 0);
	
	vector<int> v[27];
	for(int x=0;x<n;x++){
		v[(s[x] - 'a')].push_back(x);
	}
	
	for(int x=0;x<26;x++){
		for(auto idx : v[x]){
			table[idx] += v[x].size()-1;
		}
	}
	
	for(int x=n-1;x>=0;x--){
		
	}
    return 0;
}

